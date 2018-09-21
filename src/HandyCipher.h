/*
 * HandyCipher.h
 *
 *  Created on: 2018Äê9ÔÂ17ÈÕ
 *      Author: Forrest
 */

#ifndef HANDYCIPHER_H_
#define HANDYCIPHER_H_

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <random>
using namespace std;

class HandyCipher {
public:
	HandyCipher();

	void printKeyMatrix() const;
	void printLines() const;
	void print_cipher() const;
	void print_plain() const;
	void print_char_position_mapping() const;

	void setKey(string k);
	string getKey() const { return key;}

	void setPlainText(string p) {plain_text=p;}
	string getPlainText() const {return plain_text;}

	const vector<vector<char>>& getKeyMatrix() const {return key_matrix;}

	void setCipher(string);
	string getCipher();


	void encryptCoreCipher();
	void decriptCoreCipher();


	static string generateKey();
	static void saveKey(string, string ="key.txt");
	static string loadKey(string = "key.txt");


private:
	//helper functions
	void initMatrixAndMapping();
	string encryptChar(char,bool);
	bool co_line(char a, char b);

	//data
	string plain_text;
	string cipher_text;
	string key;
	vector<vector<char>> key_matrix;
	unordered_map<char,int> key_mapping;
	//helper data
	int last_line{-1};
	char last_cipher{0};
	bool last_char_2_k {false};

	string lines[20];
};

#endif /* HANDYCIPHER_H_ */
