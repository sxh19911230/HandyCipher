//============================================================================
// Name        : HandyCipher.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>


#include "HandyCipher.h"

using namespace std;


int main() {
	string tmpkey = "T?2IODWB4ZC,SM5LF.XPU9ARH8K -0NG376VQ1YJE";//HandyCipher::generateKey();
	//cout << tmpkey << endl;
	HandyCipher hc{};
	hc.setKey(tmpkey);
	//hc.print_key_analyze();
	//hc.printKeyMatrix();
	//hc.printLines();
	//hc.print_char_position_mapping();
	hc.setPlainText("ABCDEFGHIJKLMNOPQRSTUVWXYZakljdhfocqiwhefnpoiqwpncfoiqjwoeifncjqwdf");
	hc.print_plain();
	cout << endl;
	//cout << "\nstop1" << endl;
	hc.encryptCoreCipher();
	hc.print_cipher();
	cout << endl;
	hc.decrypt_init();
	//cout << "\nstop2" << endl;
	hc.decriptCoreCipher();
	hc.print_plain();


	return 0;
}




