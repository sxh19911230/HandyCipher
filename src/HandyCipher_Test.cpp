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
void swap(string&, int,int);
void swap_str(string&, int,int,int);

int main() {
	//test();
	HandyCipher hc{};
	hc.setCipher("42FB,WHZ.XWB,N9YBJ563XUM5HNMWUCHLJCBW,X?YW4MNE4F6,84EMJ85YBHK9B?5JN9UN.ZHEYH?4WK92.JNHYW4Z,FKH29J.MFX?UJ54C,3BL?4Y.4LUK,NZ6XFYW4?.HZ2NH4W34CNC?6MZBK6YZ9NBWX,6NFKCWM9YL8E526FC,?MKE2BU9Z2B?ULXK4?CEKLH4W?94H,43C?,6Z5XHF.3E4B.LWMU,3K,.L4B?,2?.HU96MBZ96Y3NF649LZYF?C,48NCUX6LMKXU63HZMUN3?KLU6X3W6JBCLXK895EJY.E3BU?CZ.U4?HWUY3L.BC.NX4.?CZUH,H9?3KN642ZUHLXJN462WH4ZHU.,KUF4N2HFCMNW5FX4,364N2WZ,EWN8B246N?6UW.K6LWCKBL.4ZNLYCWMU5KMHFX.6KN2KLH8K2MCNW5EYBN2MNCF.,FZ?6WJMK?.3EFC2.4B5CMN?FBM6Z4534C8.56MUKN5CULM?K4H?NF26C4UN.KJ9W2?BU93BY8JL?MKBW2F4H4W29KHB?XL29NYZ.ZCBU?23.EUK,9.3FW4H,HZC6WU6HXMFLHF9YL?BU2.54BNWM.F95J43C,.JZN9YKZ65,K4B.L8EJM4N6?3MUY635,N8Y59H82.K6F.93WL54ZM68X43,C58E6Z8MW3F9.YJ5EH5WZN9UN.4LB6FN3C48X.4BLEF.9J.XZF,2N8Y5JB2E34X945FZ,?8Y5E,X.JKEY5C49?J93.FB4LE39UHCZ,XW9MKZNLF6U63XK935Y8W4?HXMCLX8HJ.?.6WKZ?F5FXE9.YZ2CXJ?2BUX9Y?HWLMK?6KJMNECBK6W.?,J4CU6X.5L6N42WZ9CUZ34,CKL?9K8,X8E5?HYB4L.,6ZXJCBKML?6423Y6UMFHX?HY3B,W.HZE3.F8,4UZH6UYX?2UMHFXU6YXZNY9,XNUJKF,Z?C,32EH6J.KZ6MBK9JXC9.FZB6M49F32H98L3M2H62FN9EFBWX,ENW9K2MFXH42FBK,N?YW.FB?U2,JZ2BEXWB,2JLWCMNX4?XHF8C3JF?5NKUFLK4L6U3X?NC4N62X3KH9.J9XKXCL26YCWZ69LZNHMXZWXB,2BEXNZW?H43NMW8493E,8UCHZ2UWHYKLMU2,5KY?6ZMBYEJUELKBE?3C8XJZCHUM3KYU3?LMKEJ8?9NL8YELNYZ45BM?KBUE23U64W?H36YCN2CYW4M5U?2B.UWXBNMW9B,XF3H982X6UWBX,E.LB.5Z9NLHCBX,9YX69K2L2XCBYJHK2ZCUHE3F82KCKLB9CNMWL,3J5ZJ54ZBNK5UFZ?6W.KFEK?M3WK.5MHFK?LM2LEWN.ZKL?MU63N5,YU,6L?8Z6MX,BH?W4XUF62YE6K.WL?346N8HEF?LM9KL?F5HM,BXZCUHL9MFK?3BHMFX4HYWZFLKCXJ2ZFCHU8EJ93F.M69YZN?YHNZWB9CN.4LE9FNLZ9C4ZY96,H?W4J6KEULKCN?ZJCWZJ?F6U3JY852HJ8.KWJ9YL6UMZ6CUHB,H?W58JE,8.39F6U4NJ539EH,C34.JKF93UK4.?JZ2HN5U,MCE2N64XL2Y3X4C,3NBYNL,9BXZF?C2WCNM9F3HX5ZF,?9.EX,63YC.ZE23?M2HZ,M6ZBF93B?EL5C4,3ZJ,29H,ZF?NB3EFYU632.6ZB6MJ2X?LCX2MY3UMCWNBJ?FB6,X.4LBZBC83BEKW6.M4CKN,UWK426HYCJ3W6K.NFU,.4UK,N8M69B,H.ZK?3WF.?EB,FZ?8,CB?8H9CKJ3C4,H8KCWM.L4BF4NX.4Z?F,W,X43BKL,KNUW4?8YE43C,M5X4HLYN,?J9YF.39Y8XH568BUM,BCWNE6.W2CLX8KHLHF.K6WF93NFB9XZYKM,JFZ5JCNWZHUCYJ8.ZU9LNZEMCKZNWH4?9,W3Y6L.45ZHUCYEJB.45KZBM6EMCL6ULB.4K?M4Z348?FZ9HN64.B549ZYJZU2B?CJL64NXBCU8EJU64N2F8JEXW,HW?4ZBM2?EX63UWUXFMH6MZBHXMBXW3ZXWL4B.8C,HXF5LF39.Y58.JWZ?JH2MKL3WE3.9FU6XZJNX?Z,FWK4386.KCUHZ5L.MU23U6X.,?Z54BKH8U5C2XJ34KW.843CBZ6MF3JW.6CMNWZHBJYC?XFMHE5YBFZ4ZHUC5N.BUHN2MJ,2KH9XY6,6U9.3F,4C?ZJM3?ZFB45.NU,?K3BY58J4BL8C,29HKFMX.E4EWNC9H2,C345J8XYU8FH,UKN9KBXW3LH5?CZUHL,K5.E9XLFZ,?8,34MFX?C834XCL2MH53WNM9WB3Y6U5N,MWNX2CJ.F3CZHUXKLWJ.,H92KY?4E?B39.YZX9W,L894B.L6JKFMH59UZCHMU2,UNK?WU,KE.8H3B?U2K89UNJLCK3H.Z5YEJH92KWNE,LKCX2LZCUJW.Y2CYW.93FY8NMB86,HCZ8Z5B4X6U3BU23E9FCNJ56,Y9MBZ6L,B42N.3F9K4.MEN?BE,84W?H4UHC9423FE.CWLZNYCZULB.4UX3ZJ982.93FK,UJ?FM?LKWZ,63ULC2X.FUF.,UN.KW645L63U?WH4UK,68.M5HFLKM.LB4X.4XW95XMY?HJ8Y534CKX36,84C6Z2XLCB?26JHK8L49F.3B9624FL2JULNZY,FZ?CE46N86BZ3WK.Y4H?MK?L8,6N24E?ULUCKW.6CB9,F5C8XC2L.KW5KN.BL4U?ELH4Z?,FMWJYF5WL9ZNB4L.8EJ3Z6?4WHNME423E9N,ULJC6U3X?.LBF9.XBW,L2Z68BH?W4KU56?4HWE2Z,M68.6L529HKY8L6Z4B.52UB?CW?LMKXLEYJ92HMNWCFE3B?U2ZHUMK?CK5ZUHCK9LNY2?UMKL?9YZ6W.JU3X6H4K28H6.KENXC6N2M.6KWH29?WY4K89632XCJHW4KL8,3FMXHN26ECWMUXYCU.HL2.6EN?4WHJ5E8.ZUWENX,M,?FZKXWHJ85EFC2XL,56F,KNUJL2EN.UH,LXCYUFMH,LNZ9M?X,2H9KY8EZ6HMF85W,X.ZCF.8MBC4KBZ6M,H94WYBU2?93WXZLYM4.LBYE5WU2,4C3J6KEY5LKZ.HJY.NF6L.549LZNX9W,UNB,X9J,FZKLF2.L4BFK3JF3.9HZUC9.E?LKZN9LE8Y2?69MEN3,8WZB6M,FJ9UN85JY2FKN8YJKH823ZN384J?,.HUFHXMU.ZHJC6BZX9BN264J2LH?WL9YMWCNJK645CJL2ZU85YJM.65J8YMW834ZNL85YJH5XKW.6?C4.CHXM5C,43N?W4EU?N6F45L4X9,BHXK?M.UCHL2CX5,N?MKFHXM9EFCULJU?2BH98F,JZ4,C3ZMB,XB9UE6?KMLULFMJEL6M,?FZEJ8F85YJ.K65JUMHX4H?YBY8J5WZUH6ZM.6KW2WEC?ZJU2MNCW5UKCXL36UXZM8UC8B39.FW6JX.6M3KL,XWBCWEK,UNMLK3J5W?X969F.3NEWLYN3,8LY94?.4K42N6YLZ3,N2.CHULCJH,8?BUL.45C4KLM?UF.MK3WJKCMWNK6WUYKF4UB?2ZU.2HKZM6BCXJN,KUJ5YCHLNYF5XZ?,F8H9J?,L?M4NFW.6KE2BCK92H,8C?3LYE59CN?BEX,WB?B3N9LB4L.NKUL63XZHNUW36XU54?J,FCNWM3LF,ZJH2W4MF5X.FUFJ,.FW2EHJ5Y8LZ9?JFZKLWMCNBC8,.?U2BMEN8EJ3F.94B5CFHMX.5BYL9M?LEU?2.UHLK?M,6X3BZMY8E,Z?FC?2EZH.?EB6CHNUK52LC?MLK4?YBU?2X2JBKJWU2H26WK.BMZ8XMF823C84943,C6,HC95E,5UM.5,9BNWCM9YLZ2FCMEWF,?JHBZK?ML,32NK,NUEJ5YH.CKH8U6963XUL6U8BM2KH94FN.E6WJH5?49KH2WENBH4XL2C5YEXZBH.Z,2XCLW36XK6.N,UKEY59K2ZLN9UZCKCXJB?ECN6BMZ4,8ULN9Z5.859ZY2NJY58WKF3EZNLF?,Z5,UW.K65E.KWUHN2YN.2LXCB?NKE93Z6E8WZU.2?9E35J9?MKL,.5BFBNWCBYNFJ?ZXNZL95B.4JCXK8H6U9CL2XZJ?MF?K35Z,.9UCHZK.6LHFL2CXK4H84.94C,M.3E4C?624NHZUF5ZH.NMCW2MBZEU8B6Z2CXKU,NC?63.JLHZ.N2.54B3UX6W4?NB2U?WCNHC9NJYC834ZM6LZ9NB2?L4MX5Y3UL6BZMJX258Y2N46EF3HXMEUMB8U?B2ZU.M,?Z98KYLNX3U8ZX,2U?BYNL984K,N5?HYW6NJ5?2UF,Z?NYLWMC?WYB?2U3,M4N69BX?FZ,MBC2N426,843C54NLFU6XY.JNB,WXKJ6HMXZJ.UHCKZB6M?4YH6ZKW2K9HBCXL86BKLC4358UCZH98239CN6.JK48,6,WBXN.62F4XLJ3U6C,34EFU.ZE?UNZK,5EW,Z?FWKBCN3MKL6W.K45BHN,UKC93FYN.UZCNCM.FYJ5CEM93.FUM4?8CK4L.B3,2?ELMKC2LX83C9K4HC.2XKLE8.39FK,H2MXFHJ?,H2,XWZEFNC,LB.4JL2WH?4KMLJ5WJKN4FL54J2LC?KMLF?Z3H4C3,8W2N8,3W5,H29MKXFMNU9WB2L6FN3Y6UMXHFBNFUCZKH28FBL.4EWNXWMC?LMKY8L6WK5KU8J5Y2BUWUN.B4LE9F.8H9MECUC9CZHUXZHUMEWLN?FCZHUFN6?,FZWF.2.HCXKLW4H?NYKM35KUJ53XYB8X63U9BXFU3X6HFMU2.XHMJFZ?X8J5Y?BN6?L3NUB4L.XH5CNEW324N6?FCNWMUXY,63X8JYEK.J4H3B,WXEBUWK6.2XCBMZ459CN4YHW3X6U5XMC2WY4JLXHWUN8JNZ8EYCHUZE.398H3L?M,5NKCBZM6,?9UX3982ML?KBLH4X2CLF4N2ZJ,6F2.49UZHC?YHB?2ZY86HL9ZN85EMNCE,.BL49K,.FU5KN3,C4KH23N2HUZC?.BH49MBZ6XL,XKML?W9BKLF3.23L4.M4N26E.9UHCZ2N6CN4N.4JL2CM32,XZ9YMB8L2CXWXBFJBFXHMNLZ4LB9XKC4FJ?Z36Z?,FBZ6,H2YJ853JYEXZLN9MFXZFH46KJ.?U2BHJ2L685U4.XKH29MB62EXU3ZUC.X?25J9.3FKM?C.W9,2LXC9LFZ3C,4KCH3N624JCL2Z,?3UY,XWBC9,BY8E4HK2H9C.HNMW8EYFHMXE9FWL45J8EH29KZ6M246CUZH396UMFHXEY8.F45.L82KYX6,X?6N42W2N89KF,?Z64M86L2CJW856Z?,FZ3M89Z6BM,?H493.FKB?2,C836ZW3.9FUCHW5JB2U?9KY58FN82,L9ZNXLJ4HNBW,MKL6F2N?L8U6LCX2YX6WFM5Z?JBL.4E.9C2X?4HW3HFWMEK,NU9W,X8ZBJ8E4.?KLMU5,EY5JLH?W49YN.6?WY2N3KC6W.KB68X.94H?YK.6JMNCWLXUNB2U?XNK53WNMCBEUHUZCXB,.WKJU6LKHL,XWBH9JF,L.B5Z6,2?.E3ZFU5N,MCEL4UHCZKM32JLE9FCUWY?NU,KB?.CHENCWLUX4H6U3XZ5LBN46,C4MLKFZKXU63ZH.5KN?4J,FZWBXUX3B?4.LBK9HLY943WU2BN2,F?ZKW2H,WBX8MBCUMLK4ZY6.LH4W?XYU92KH,9BX.BK8H2NU2BU?Y3UF39C.HU8MZ3H2K9?WHJ2WZ,?F6MZ5Y8F2MUN6.KJB9MHF8E568F5W9X,.9B?U28MZ34XFY8J5?M9JY8,W96WK.X3NC?BU25U,NJ.W8HKZFBH4?WU6X4JC9FWX2NB,");
	//hc.core_cipher_attack_init("ON2TPDSMKYCVER741UG80?-ZX");
	//hc.core_cipher_attack_init("PON2TYDSMK7CVER841UGX0?-Z");
	//string key = ",.2345689?BCEFHJKLMNUWXYZ";


	string key_tmp = "HMXN6K3UW4Z9?5,LJFCBYE2.8";
	//hc.printKeyMatrix();
	//hc.printLines();
	string plain = "For the most part, however, Bucks love was expressed in adoration. While he went wild with happiness when Thornton touched him or spoke to him, he did not seek these tokens. Unlike Skeet, who was wont to shove her nose under Thorntons hand and nudge and nudge till petted, or Nig, who would stalk up and rest his great head on Thorntons knee, Buck was content to adore at a distance. He would lie by the hour, eager, alert, at Thorntons feet, looking up into his face, dwelling upon it, studying it, following with keenest interest each fleeting expression, every movement or change of feature. Or, as chance might have it, he would lie farther away, to the side or rear, watching the outlines of the man and the occasional movements of his body. And often, such was the communion in which they lived, the strength of Bucks gaze would draw John Thorntons head around, and he would return the gaze, without speech, his heart shining out of his eyes as Bucks heart shone out. -Jack London - The Call Of The Wild";

	hc.core_cipher_attack_init(key_tmp);
	hc.core_cipher_attack(plain,500);
	cout << hc.core_cipher_attack_decrypt(plain,key_tmp) << endl;
	int score = 0, new_score = 0;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();


	string key_tmp2{};

	do {
		if (new_score == score) {
			if (new_score < -24) {
				cout << new_score << ' '<<key_tmp << endl;
				cout << hc.core_cipher_attack_decrypt(plain,key_tmp) << endl;
			}
			shuffle (key_tmp.begin(), key_tmp.end(), std::default_random_engine(seed));
			hc.core_cipher_attack_init(key_tmp);
			new_score = hc.core_cipher_attack(plain,50);
		}
		else {
			score=new_score;
			key_tmp = key_tmp2;
		}

		for (int i = 0; i < 25; ++i) {
			for (int j = i+1; j < 25; ++j) {

				string key = key_tmp;
				swap(key,i,j);

				hc.core_cipher_attack_init(key);
				int t = hc.core_cipher_attack(plain,50);
				if (t < new_score) {
					key_tmp2=key;
					new_score=t;
				}
			}
		}


		for (int k = 0; k < 4; ++k)
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j) {
					string key = key_tmp;
					swap_str(key,i,j,k);
					hc.core_cipher_attack_init(key);
					int t = hc.core_cipher_attack(plain,50);
					if (t < new_score) {
						key_tmp2=key;
						new_score=t;
					}
				}


	} while(new_score > -30);

	cout << score << ' ' <<  key_tmp << endl;
	cout << hc.core_cipher_attack_decrypt(plain,key_tmp);

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

void climb_next(string key, string& plain) {

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

void swap(string& key,int i,int j) {
	char c = key[i];
	key[i] = key[j];
	key[j] = c;
}

void swap_str(string& key,int i,int j, int k) {
	if (k==0) {
		for(int n = 0; n < 5; ++n) {
			swap(key,i*5+n, j*5+n);
		}
	}
	else if (k ==1) {
		for(int n = 0; n < 5; ++n) {
			swap(key,i+n*5, j+n*5);
		}
	}
	else if (k ==2) {
		for(int n = 0; n < 5; ++n) {
			swap(key,(n+i)%5,(n+j)%5);
		}
	}
	else if (k ==3) {
		for(int n = 0; n < 5; ++n) {
			swap(key,(n+i)%5,(j-n+5)%5);
		}
	}
}
