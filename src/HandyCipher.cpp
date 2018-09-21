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

#include "HandyCipher.h"

// random generator function:
int myrandom (int i) { return std::rand()%i;}

HandyCipher::HandyCipher() {}


void HandyCipher::initMatrixAndMapping() {
	string tmp;
	copy_if(key.begin(),key.end(),back_inserter(tmp), [](char t){return t!=' ';});
	key_matrix.clear();
	for (int i = 0; i < 5; ++i) {
		key_matrix.push_back(vector<char>{});
		for (int j = 0; j < 8; ++j)
			key_matrix[i].push_back(tmp[i*8+j]);
	}
	int k=0;
	for (auto i = key.begin();i!=key.end();++i)
		if ('0' > *i || *i > '9' )key_mapping[*i]=k++;

	for (int i = 0; i < 20; ++i) {
		//column
		if (i < 5)
			for (int j = 0; j < 5; ++j)
				lines[i].push_back( key_matrix[i][j]);
		else if (i < 10)
			for (int j = 0; j < 5; ++j)
				lines[i].push_back( key_matrix[j][i-5]);
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


void HandyCipher::encryptCoreCipher() {
	srand(time(NULL));
	bool flip=false;
	cipher_text = "";
	for(char c : plain_text) {
		cipher_text += encryptChar(c,flip);
		flip=!flip;
	}
}

string HandyCipher::encryptChar(char t, bool flip) {
	int num = key_mapping[t];
	int line_choice;

	string r;

	//if this num is not 2^k
	if (num & (num - 1)) {


		bool found = false;
		while (!found) {
			line_choice = rand()%20;
			while(line_choice == last_line) line_choice  = rand()%20;

			//generate it
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
			for(int i = 0,numtmp=num;numtmp;++i,numtmp>>=1)
				if (numtmp&1) r+= flip ? lines[line_choice][4-i] : lines[line_choice][i];

			//if last char is 2^k
			if (last_char_2_k) {
				if (!co_line(last_cipher,r[0])){
					found = true;
					last_cipher=r.back();
					last_char_2_k = true;
					last_line = line_choice;
				}
			}
			//if last char is not 2^k
			else {
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

void HandyCipher::decriptCoreCipher() {

}

void HandyCipher::print_cipher() const {
	cout << cipher_text;
}

void HandyCipher::print_plain() const {
	cout << plain_text;
}

void HandyCipher::print_char_position_mapping() const {
	for(auto i = key_mapping.begin(); i!= key_mapping.end();++i) cout << i->first << ": " << i->second << '\n';
}

bool HandyCipher::co_line(char a, char b) {
	for (string l:lines)
		if (std::any_of(l.begin(),l.end(),[=](char t1) {return t1 == a;}) && std::any_of(l.begin(),l.end(),[=](char t1) {return t1 == b;}))
			return true;
	return false;
}
