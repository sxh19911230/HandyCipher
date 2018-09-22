/*
 * HandyCipher.h
 *
 *  Created on: 2018��9��17��
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
	void print_char_position_mapping() const;
	void print_key_analyze();

	void setKey(string k);
	string getKey() const { return key;}

	void setCipher(string c){cipher_text = c;}
	void setPlainText(string p);
	const string& get_cipher() const;
	const string& get_plain() const;

	bool encryptCore();
	void null_char_insert();
	bool encrypt();

	bool decryptCore();
	void null_char_remove();
	bool decrypt();


	static string generateKey();
	static void saveKey(string, string ="key.txt");
	static string loadKey(string = "key.txt");


private:
	//helper functions
	void initMatrixAndMapping();
	string encryptChar(char,bool);
	bool co_line(char a, char b);
	void decrypt_init();
	const vector<vector<char>>& getKeyMatrix() const {return key_matrix;}

	//data
	string plain_text;
	string cipher_text;
	string key;
	vector<vector<char>> key_matrix;
	unordered_map<char,int> char_position_mapping;
	unordered_map<int,char> position_char_mapping;
	vector<char> null_set;
	//helper data
	char last_char{};
	int last_line{-1};
	char last_cipher{0};
	bool last_char_2_k {false};

	unordered_map<string, char> key_char_mapping[2];

	string lines[20];
};

#endif /* HANDYCIPHER_H_ */
