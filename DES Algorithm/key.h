//
//  DESEncrypt.h
//  DES Algorithm
//
//  Created by Yi Zhou on 2017/4/29.
//  Copyright © 2017年 Yi Zhou. All rights reserved.
//

#ifndef key_h
#define key_h
#include <bitset>
#include <string>
#include <fstream>
#include "box.h"
using namespace std;
bitset<56> keyplus;
bitset<28> c[17];
bitset<28> d[17];

class getkey
{
private:
    int offset[17]={0,1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
    inline bitset<28> moveleft(const bitset<28>& myset,const int n)//move left in circulation
    {
        bitset<28> answer;
        for(int i=0;i<=27;i++)
        {
            answer[(i+n)%28]=myset[i];
        }
        return answer;
    }

    void Getkeyplus(const bitset<64> original)
    {
        ifstream infile("pc1.txt");
        int num;
        int i=55;
        while(infile>>num)
        {
            keyplus[i]=original[64-num];
            i--;
        }
        infile.close();
        for(int i=0;i<=27;i++)
        {
            d[0][i]=keyplus[i];
            c[0][i]=keyplus[28+i];
        }
    }

    void Getsubkey()
    {
        for(int i=1;i<=16;i++)
        {
            c[i]=moveleft(c[i-1], offset[i]);
            d[i]=moveleft(d[i-1], offset[i]);
        }
    
        bitset<56> temp[17];
        for(int i=1;i<=16;i++)
            for(int j=0;j<=27;j++)
        {
            temp[i][j]=d[i][j];
            temp[i][j+28]=c[i][j];
        }
        ifstream infile("pc2.txt");
        int num;
        int i=47;
    
        while(infile>>num)
        {
            for(int j=1;j<=16;j++)
            {
                subkey[j][i]=temp[j][56-num];
            }
            i--;
        }
        infile.close();
    }
public:
    void getmykey(bitset<64> original)
    {
        Getkeyplus(original);
        Getsubkey();
    }
};
#endif /* DESEncrypt_h */
