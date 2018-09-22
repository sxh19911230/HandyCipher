/*
 * HandyCipher.cpp
 *
 *  Created on: 2018Äê9ÔÂ17ÈÕ
 *      Author: Forrest
 */

#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <bitset>
#include <list>

#include "HandyCipher.h"

int myrandom (int i) { return std::rand()%i;}

struct RedoLast{};
struct NotDoable{};

HandyCipher::HandyCipher() {}

void HandyCipher::initMatrixAndMapping() {
	string tmp;
	copy_if(key.begin(),key.end(),back_inserter(tmp), [](char t){return t!=' ';});

	//matrix
	key_matrix.clear();
	null_set.clear();
	for (int i = 0; i < 5; ++i) {
		key_matrix.push_back(vector<char>{});
		for (int j = 0; j < 8; ++j) {
			key_matrix[i].push_back(tmp[i*8+j]);
			//null characters set
			if (j>=5) null_set.push_back(tmp[i*8+j]);
		}
	}
	// char position mapping
	char_position_mapping.clear();
	position_char_mapping.clear();
	int k=1;
	for (auto i = key.begin();i!=key.end();++i)
		if ('0' > *i || *i > '9' ) {
			char_position_mapping[*i]=k;
			position_char_mapping[k] =*i;
			++k;
		}

	//line map
	for (int i = 0; i < 20; ++i) lines[i].clear();

	for (int i = 0; i < 20; ++i) {
		//column
		if (i < 5)
			for (int j = 0; j < 5; ++j)
				lines[i].push_back( key_matrix[j][i]);
		//row
		else if (i < 10)
			for (int j = 0; j < 5; ++j)
				lines[i].push_back( key_matrix[i-5][j]);
		//dia
		else if (i < 15)
			for (int j = 0; j < 5; ++j)
				lines[i].push_back( key_matrix[j][(j+i)%5]);
		else if (i < 20)
			for (int j = 0; j < 5; ++j)
				lines[i].push_back( key_matrix[j][(i-j)%5]);
	}

}

void HandyCipher::printKeyMatrix() const {

	for (auto i = key_matrix.begin(); i!= key_matrix.end();++i) {
		for (int j = 0; j < 8; ++j){
			if (j == 5) cout << "| ";
			cout << (*i)[j] << ' ';
		}
		cout << '\n';
	}
}

void HandyCipher::printLines() const {
	for(int i = 0; i < 20; ++i)
		cout << lines[i] <<'\n';
}

void HandyCipher::saveKey(string key, string filename){
	ofstream os (filename, std::ofstream::out);
	os << key;
	os.close();
}

string HandyCipher::loadKey(string filename) {
	ifstream is(filename, std::ifstream::in);
	string tmp;
	if (is) {
		getline(is,tmp);
		is.close();
	} else {
		cout << "Unable to load key from file: " + filename;
		exit(0);
	}
	return tmp;
}

string HandyCipher::generateKey() {
	srand(time(NULL));
	string char_set="ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-? 0123456789";
	std::random_shuffle ( char_set.begin(), char_set.end(),myrandom);
	return char_set;
}

void HandyCipher::setKey(string k) {
	key=k;
	initMatrixAndMapping();
}


bool HandyCipher::encryptCore() {
	srand(time(NULL));

	bool flip=true;
	cipher_text = "";
	int lastciphersize=0;
	for(int i = 0; i < (int)plain_text.size();i++) {

		try {
			string tmp = encryptChar(plain_text[i],flip);
			lastciphersize=tmp.size();
			cipher_text += tmp;
			last_char=plain_text[i];


			flip=!flip;
		} catch (RedoLast&) {
			i-=2;
			cipher_text = cipher_text.substr(0,cipher_text.size()-lastciphersize);
		} catch (NotDoable&) {
			return false;
		}
	}
	return true;
}

string HandyCipher::encryptChar(char t, bool flip) {
	int num = char_position_mapping[t];
	int line_choice;

	string r;

	//if this num is not 2^k
	if (num & (num - 1)) {


		bool found = false;
		while (!found) {
			line_choice = rand()%20;
			while(line_choice == last_line) line_choice  = rand()%20;

			r= "";
			for(int i = 0,numtmp = num;numtmp;++i,numtmp>>=1)
				if (numtmp&1) r+= flip ? lines[line_choice][4-i] : lines[line_choice][i];
			std::random_shuffle ( r.begin(), r.end(),myrandom);

			//if last char is 2^k
			if (last_char_2_k) {
				if (!co_line(last_cipher,r[0])){
					found = true;
					last_cipher=r.back();
					last_char_2_k = false;
					last_line = line_choice;
				}
			}
			//if last char is not 2^k
			else {
				//if (last_line >=0) cout <<  << endl;
				if (last_line < 0 ||
						!std::any_of(lines[last_line].begin(),lines[last_line].end(),[=](char t1) {return t1 == r[0];})) {
					found = true;
					last_cipher=r.back();
					last_char_2_k = false;
					last_line = line_choice;
				}
			}
		}
	}
	//if this num is 2^k
	else {
		bool found = false;
		while (!found) {

			line_choice = rand()%5;
			while(line_choice == last_line) line_choice  = rand()%5;
			r="";
			int i = 0;
			for(int numtmp=num;numtmp;++i,numtmp>>=1)
				if (numtmp&1) break;
			r = flip ? lines[line_choice][4-i] : lines[line_choice][i];

			//if last char is 2^k
			if (last_char_2_k) {
				//No way to encrypt
				if (char_position_mapping[t] * char_position_mapping[last_char] == 16) {
					//cout << "not able to find a way to encrypt" << endl;
					throw NotDoable{};
				}
				if (!co_line(last_cipher,r[0])){
					found = true;
					last_cipher=r.back();
					last_char_2_k = true;
					last_line = line_choice;
				}
			}
			//if last char is not 2^k
			else {
				//This cipher always land on the previous cipher line, so need redo the previous
				if ((!flip && (i+5==last_line)) ||(flip && (9-i==last_line))) throw RedoLast{};

				if (last_line < 0 ||
						!std::any_of(lines[last_line].begin(),lines[last_line].end(),[=](char t1) {return t1 == r[0];})) {
					found = true;
					last_cipher=r.back();
					last_char_2_k = true;
					last_line = line_choice;
				}
			}
		}
	}
	//cout << t << ' ' << r << endl;
	return r;
}

const string& HandyCipher::get_cipher() const {
	return cipher_text;
}

const string& HandyCipher::get_plain() const {
	return plain_text;
}

void HandyCipher::print_char_position_mapping() const {
	for(auto i = char_position_mapping.begin(); i!= char_position_mapping.end();++i) cout << i->first << ": " << i->second <<
			' ' << bitset<5>( i->second ) <<'\n';
}

bool HandyCipher::encrypt() {
	bool r = encryptCore();
	if (r) null_char_insert();

	return r;
}

bool HandyCipher::decrypt() {
	decrypt_init();
	null_char_remove();
	return decryptCore();
}

void HandyCipher::null_char_insert() {
	srand(time(0));
	string tmp {move(cipher_text)};
	double ran;

	for(auto i = tmp.begin();;) {
		ran =  (double) rand()/RAND_MAX ;
		if (ran < 0.625) {
			if (i==tmp.end()) break;
			cipher_text.push_back(*i);
			++i;
		} else
			for (;;) {
				//random char from null set
				char c = null_set[rand()%15];
				//used in last 5 times?
				int pos = find(cipher_text.rbegin(),cipher_text.rbegin()+6,c) - cipher_text.rbegin();

				if (rand()/RAND_MAX > (5-pos)/5.0) {
					cipher_text.push_back(c);
					break;
				}
			}
	}
}

void HandyCipher::null_char_remove() {
	string tmp {move(cipher_text)};
	copy_if(tmp.begin(),tmp.end(),back_inserter(cipher_text),[this](char c){return find(null_set.begin(), null_set.end(), c) == null_set.end();});
}

bool HandyCipher::co_line(char a, char b) {
	for (string l:lines)
		if (std::any_of(l.begin(),l.end(),[=](char t1) {return t1 == a;}) && std::any_of(l.begin(),l.end(),[=](char t1) {return t1 == b;}))
			return true;
	return false;
}

void HandyCipher::print_key_analyze() {
	cout << position_char_mapping[1] << " and " << position_char_mapping[16] << " cannot be adjacent\n"
			<< position_char_mapping[2] << " and " << position_char_mapping[8] << " cannot be adjacent\n"
			<< position_char_mapping[4] << " cannot appear in a row" << endl;
}

void HandyCipher::setPlainText(string p) {
	plain_text=p;
	std::transform(plain_text.begin(),plain_text.end(),plain_text.begin(),::toupper);
}



void HandyCipher::decrypt_init() {
	key_char_mapping[0].clear();
	key_char_mapping[1].clear();
	for (auto cp :char_position_mapping) {
		int position = cp.second;
		char c = cp.first;
		for (int line_num = 0; line_num < 20; ++line_num) {
			if (line_num >4 && !(position & (position-1))) break;
			string r= "",rf="";
			for(int i = 0,numtmp = position;numtmp;++i,numtmp>>=1)
				if (numtmp&1) {
					r+= lines[line_num][i];
					rf+=lines[line_num][4-i];
				}
			std::sort(r.begin(),r.end());
			std::sort(rf.begin(),rf.end());
			key_char_mapping[0][r] = c;
			key_char_mapping[1][rf] = c;
			//cout << r << " : " << c << endl;
		}
	}
}

bool HandyCipher::decryptCore() {
	plain_text="";
	int current_position = 0;
	bool flip = true;
	while (current_position < (int)cipher_text.size()) {
		//cout << plain_text << endl;
		for (int i = 5; i >0;--i) {
			string key = cipher_text.substr(current_position,i);
			sort(key.begin(),key.end());
			if (key_char_mapping[flip].count(key)){
				plain_text+=key_char_mapping[flip].at(key);
				current_position+=i;
				flip=!flip;
				break;
			}
		}
	}
	return true;
}
