/*
 * HandyCipher.cpp
 *
 *  Created on: 2018��9��17��
 *      Author: Forrest
 */

#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>

#include "HandyCipher.h"

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
	for (auto i = key.begin();i!=key.end();++i) key_mapping[*i]=k++;
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
	string char_set="ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-? 0123456789";
	std::random_shuffle ( char_set.begin(), char_set.end());
	return char_set;
}

void HandyCipher::setKey(string k) {
	key=k;
	initMatrixAndMapping();
	for(auto i = key_mapping.begin(); i!= key_mapping.end();++i) cout << i->first << ": " << i->second << '\n';
}


void HandyCipher::encryptCoreCipher() {

}

string HandyCipher::encryptChar(char t) {
	int bin = key_mapping[t];

	return "";
}

void HandyCipher::decriptCoreCipher() {

}
