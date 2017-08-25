//
//  Encrypt.h
//  DES Algorithm
//
//  Created by Yi Zhou on 2017/4/29.
//  Copyright © 2017年 Yi Zhou. All rights reserved.
//

#ifndef Encrypt_h
#define Encrypt_h
#include "key.h"
#include "box.h"
#include "function.h"
class Encrypt
{
public:
    void GetCiphertext(const bitset<64>& plaintext)
    {
        initialize();
        getip(plaintext);
        cout<<"Left:"<<Left[0]<<" Right:"<<Right[0]<<endl;
        for(int i=1;i<=16;i++)
        {
            iterate(i,Left,Right);
        }
        bitset<64> temp;
        for(int i=0;i<=31;i++)
        {
            temp[i]=Left[16][i];
            temp[32+i]=Right[16][i];
        }
        
        
        for(int i=63;i>=0;i--)
        {
            myCiphertext[i]=temp[64-IP_1[63-i]];
        }
        
    }
};

#endif /* Encrypt_h */
