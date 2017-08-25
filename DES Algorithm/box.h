//
//  box.h
//  DES Algorithm
//
//  Created by Yi Zhou on 2017/5/3.
//  Copyright © 2017年 Yi Zhou. All rights reserved.
//

#ifndef box_h
#define box_h
#include <bitset>
using namespace std;
bitset<64> IP;
bitset<32> Left[17];
bitset<32> Right[17];
int IP_1[64];
int E[48];
int S[9][4][16];
int P[32];
bitset<64> myCiphertext;
bitset<48> subkey[17];
bitset<64> myDeciphertext;
#endif /* box_h */
