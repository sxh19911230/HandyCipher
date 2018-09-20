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
	string tmpkey = HandyCipher::generateKey();
	cout << tmpkey << '\n';
	HandyCipher hc{};
	hc.setKey(tmpkey);
	hc.printKeyMatrix();

	return 0;
}




