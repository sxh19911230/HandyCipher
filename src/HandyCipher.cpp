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
	for(auto i = key_mapping.begin(); i!= key_mapping.end();++i) cout << i->first << ": " << i->second << '\n';
}


void HandyCipher::encryptCoreCipher() {
	srand(time(NULL));


}

string HandyCipher::encryptChar(char t) {
	int num = key_mapping[t];
	return "";
}

void HandyCipher::decriptCoreCipher() {

}

void HandyCipher::choose_line() {
	int i = rand() % 20;

}
