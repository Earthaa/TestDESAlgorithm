//
//  descrypt.h
//  DES Algorithm
//
//  Created by Yi Zhou on 2017/5/3.
//  Copyright © 2017年 Yi Zhou. All rights reserved.
//

#ifndef descrypt_h
#define descrypt_h
#include "box.h"
#include "function.h"
class Descrypt
{
public:
    void GetPlaintext(const bitset<64>& ciphertext)
    {
        
        getip(ciphertext);
        swap(Left[0], Right[0]);
        cout<<"Left:"<<Left[0]<<" Right:"<<Right[0]<<endl;
        for(int i=1;i<=8;i++)
        {
            swap(subkey[i], subkey[17-i]);
        }
        for(int i=1;i<=16;i++)
        {
            iterate(i,Right,Left);
        }
        bitset<64> temp;
        for(int i=0;i<=31;i++)
        {
            temp[i]=Right[16][i];
            temp[32+i]=Left[16][i];
        }
        
        for(int i=63;i>=0;i--)
        {
            myDeciphertext[i]=temp[64-IP_1[63-i]];
        }
    }
    
};

#endif /* descrypt_h */
