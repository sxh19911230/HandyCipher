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
	//hc.printKeyMatrix();
	//hc.printLines();
	//hc.print_char_position_mapping();
	hc.setPlainText("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	hc.print_plain();
	cout << '\n';
	hc.encryptCoreCipher();
	hc.print_cipher();

	return 0;
}




