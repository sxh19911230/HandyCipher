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
	HandyCipher hc{};
	string tmpkey = "T?2IODWB4ZC,SM5LF.XPU9ARH8K -0NG376VQ1YJE";//HandyCipher::generateKey();
	//cout << tmpkey << endl;
	hc.setKey(tmpkey);
	//hc.print_key_analyze();
	//hc.printKeyMatrix();
	//hc.printLines();
	//hc.print_char_position_mapping();
	hc.setPlainText("ABCDEFGHIJKLMNOPQRSTUVWXYZakljdhfocqiwhefnpoiqwpncfoiqjwoeifncjqwdf");
	//cout << hc.get_plain() << endl;


	//hc.setCipher("N,IQ5OI2HNG2DVA1XUP.3BAF-W4UIO?UXAFGZTHU2R5,ZCDSU1BERS.826W,LXH0P-3QOURWYMTH4VLZQ68DZ?5MYU4OFUXPMSH8R0IWP-?8.OESU0TP0HELDWKBU5LS0.0G2,PJ9WMIZL54-PWS945RCHDF4AEJT7BNDM,EUHY74TOT.G3SI7ENVJ64UW627HGT6BZ50WSUPG2,EM9CD3.IN74FHX-A.B5T3P6KDLSO,EG9NJBPKSQM-LEI5.UJK085-Y4U9?Z3D5RFO2A.ZJ8");
	if (hc.encrypt()) {
		cout << hc.get_cipher() << endl;
		cout << "size of cipher: " << hc.get_cipher().size() << endl;
		if (hc.decrypt()) cout << hc.get_plain() << endl;
	}


	//hc.setKey("ON2TP3FLDSMKY,5ACVER7WIH41UG8.960 ?-ZXQJB");
	//hc.setCipher("Z0XSNDPR?EM-OXE8DOM1?PNZ7YZ8-G0ENUZ7TO2D1ZSCRKZPG8-VP?0S21-TDKNK?72DO148ON0?MD0NMGY1M2DP10PCRNKYN80USO78PMN24NXOUYR814E1XD8DNKT0-SYD8?X-84UG7RX0ZGX1?MY1?NKUMXGRGO0D8U0TM2K?MZXCSZ107OP?D7GPGM?107P0?EKP102OP?28TZK8VDZNMTUXK-RGPVOSP?VNTYDS4OCGY7PS2YOZUPG4PG-0ZXUTYMTECX14-0U2-O?T8XTPMY?RY2S?0KP10E?VNYD1R7VYZG81GPRN02M-E41O40DCX7PM2DNY-TDPCV27OSX1M4SNYTMDXDN4E?SNXOZDP4?8G0TCNO82XY7S0?2SZY01ZDVGXRECNZND7SO1PEYKMN8MR2X0ST1CPO8S20R8NUZ41ZDUN8MZXR7Z1D21D?P?4RCM2-8CKENG-TV4ZK8");
	//hc.print_char_position_mapping();

	//hc.decrypt();
	//cout << hc.get_plain();
}
