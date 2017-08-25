//
//  main.cpp
//  DES Algorithm
//
//  Created by Yi Zhou on 2017/4/27.
//  Copyright © 2017年 Yi Zhou. All rights reserved.
//

#include <iostream>
#include <bitset>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include "DES.h"

int main()
{
    string mytext="cdefgab";
    //getline(cin,mytext);
    cout<<"加密："<<endl;
    //cout<<string_to_hex(mytext)<<endl;
    string key="0x0E329232EA6D0D73";
    a->getmykey(string_to_bit(key));
    //cin>>mytext;
    bitset<64> p("100101001111101010101111111000011");
    enc->GetCiphertext(p);
    cout<<myCiphertext<<endl;
    cout<<"解密:"<<endl;
    a->getmykey(string_to_bit(key));
    des->GetPlaintext(myCiphertext);
    
}
