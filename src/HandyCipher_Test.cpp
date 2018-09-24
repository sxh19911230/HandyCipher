//============================================================================
// Name        : HandyCipher.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <thread>
#include <future>
#include <functional>
#include <map>
#include <set>

#include "HandyCipher.h"

using namespace std;


void test();


int main() {
	//test();
	HandyCipher hc{};
	hc.setCipher("Z0XSN2S-7MR0TZR4NOM1?PNZYRXZPT8UNZXCN1VYGYC-?K7T?1X2EDSTMDKY2UNXTVMOY2?KNO14RNX0?8DUTMOS8G4NGP-GC7R1OSU2E41O4P48EK12SZ7GXK8VCOS4UKTZ17YX2TPO8X-2UG8?UX-RC7KVRXZ4V2M-P2ZOSTKZMG8EV71?EDY074KO1MZ8XNVODEUM2-8U4P0UTZKUSZCPDO1XKXC8VN412RTZM2DPRUO12MES2YOZX024PGZ1-T8?0SO720YOVNZ0X2?P-1X4P281UND2STY1C-27?TXU7VRKX8K?4NCE7D-7NVCGKRZTE7CPKCVOXSTKNDTRSOXUS8KTSO720TY4R2ZS0PSXOKY-1X2O14P8EV7SPY418D8G?YRX4P87OZECVMN7NGC1-O4DCP?2YZ0-T-K42GTRZ?12MZDU0?Z7RX4-4Y21DXNU?T4-NDREY71T-8P7K0G");

	//hc.core_cipher_attack_init("ON2TPDSMKYCVER741UG80?-ZX");
	//hc.core_cipher_attack_init("PON2TYDSMK7CVER841UGX0?-Z");
	string key = "ODC40NSV1?2MEU-TKRGZPY78X";

	hc.core_cipher_attack_init(key);
	//hc.printKeyMatrix();
	//hc.printLines();
	string plain = "IT HAUNTS ME, THE PASSAGE OF TIME. I THINK TIME IS A MERCILESS THING. I THINK LIFE IS A PROCESS OF BURNING ONESELF OUT AND TIME IS THE FIRE THAT BURN-S YOU. BUT I THINK THE SPIRIT OF MAN IS A GOOD ADVERSARY.  -- TENNESSEE WILLIAMS";

	if (!hc.core_cipher_attack(plain))  cout << "no" << endl;
	/*
	string plain = "For the most part, however, Bucks love was expressed in adoration. While he went wild with happiness when Thornton touched him or spoke to him, he did not seek these tokens. Unlike Skeet, who was wont to shove her nose under Thorntons hand and nudge and nudge till petted, or Nig, who would stalk up and rest his great head on Thorntons knee, Buck was content to adore at a distance. He would lie by the hour, eager, alert, at Thorntons feet, looking up into his face, dwelling upon it, studying it, following with keenest interest each fleeting expression, every movement or change of feature. Or, as chance might have it, he would lie farther away, to the side or rear, watching the outlines of the man and the occasional movements of his body. And often, such was the communion in which they lived, the strength of Bucks gaze would draw John Thorntons head around, and he would return the gaze, without speech, his heart shining out of his eyes as Bucks heart shone out. -Jack London - The Call Of The Wild";
	HandyCipher hc{};
	hc.setPlainText(plain);
	hc.setKey(HandyCipher::generateKey());
	while(!hc.encryptCore())
		hc.setKey(HandyCipher::generateKey());
	cout << hc.getKey() << endl;
	hc.printKeyMatrix();
	hc.print_char_position_mapping();
	cout <<endl;
	cout << hc.get_cipher() << endl;
	*/
}

void test() {
	HandyCipher hc{};
	//string tmpkey = "T?2IODWB4ZC,SM5LF.XPU9ARH8K -0NG376VQ1YJE";//HandyCipher::generateKey();
	//cout << tmpkey << endl;
	//hc.setKey(tmpkey);
	//hc.print_key_analyze();
	//hc.printKeyMatrix();
	//hc.printLines();
	//hc.print_char_position_mapping();
	//hc.setPlainText("ABCDEFGHIJKLMNOPQRSTUVWXYZakljdhfocqiwhefnpoiqwpncfoiqjwoeifncjqwdf");
	//cout << hc.get_plain() << endl;


	//hc.setCipher("N,IQ5OI2HNG2DVA1XUP.3BAF-W4UIO?UXAFGZTHU2R5,ZCDSU1BERS.826W,LXH0P-3QOURWYMTH4VLZQ68DZ?5MYU4OFUXPMSH8R0IWP-?8.OESU0TP0HELDWKBU5LS0.0G2,PJ9WMIZL54-PWS945RCHDF4AEJT7BNDM,EUHY74TOT.G3SI7ENVJ64UW627HGT6BZ50WSUPG2,EM9CD3.IN74FHX-A.B5T3P6KDLSO,EG9NJBPKSQM-LEI5.UJK085-Y4U9?Z3D5RFO2A.ZJ8");
	//if (hc.encrypt()) {
	//	cout << hc.get_cipher() << endl;
	//	cout << "size of cipher: " << hc.get_cipher().size() << endl;
	//	if (hc.decrypt()) cout << hc.get_plain() << endl;
	//}


	//cout << endl;
	//hc.setKey("ON2TP3FLDSMKY,5ACVER7WIH41UG8.960 ?-ZXQJB");
	//hc.printKeyMatrix();
	//hc.printLines();


	//cout << cipher << endl;
	//hc.setCipher(cipher);

	//cout << hc.get_cipher() << endl;
	//hc.decrypt_init();
	//hc.null_char_remove();
	//cout << hc.get_cipher() << endl;

	//cout << hc.get_plain();
}

