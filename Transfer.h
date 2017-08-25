//
//  transfer.h
//  DES Algorithm
//
//  Created by Yi Zhou on 2017/4/30.
//  Copyright © 2017年 Yi Zhou. All rights reserved.
//

#ifndef transfer_h
#define transfer_h
#include <string>

bitset<64> string_to_bit(const string& str)//transfer hex-string to bit
{
    bitset<64> result;
    long long tmp=strtoll(str.c_str(), NULL, 16);
    result=tmp;
    return result;
}

string string_to_hex(const string& str) //transfer string to hex-string
{
    string result="0x";
    string tmp;
    stringstream ss;
    for(int i=0;i<str.size();i++)
    {
        ss<<hex<<int(str[i])<<endl;
        ss>>tmp;
        result+=tmp;
    }
    return result;
}

#endif /* transfer_h */
