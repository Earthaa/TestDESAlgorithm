//
//  function.h
//  DES Algorithm
//
//  Created by Yi Zhou on 2017/5/3.
//  Copyright © 2017年 Yi Zhou. All rights reserved.
//

#ifndef function_h
#define function_h
#include "box.h"
#include <bitset>
using namespace std;

bitset<32> func(const int n,bitset<32>* myleft,bitset<32>* myright)//function f
{
    bitset<32> result;
    bitset<48> extend_right;
    for(int i=47;i>=0;i--)
        extend_right[i]=myright[n-1][32-E[47-i]];
    bitset<48> temp;
    temp=extend_right^subkey[n];
    
    for(int k=8;k>=1;k--)
    {
        bitset<2> row;
        bitset<4> column;
        row[0]=temp[(k-1)*6];
        row[1]=temp[(k-1)*6+5];
        int i=(int)row.to_ulong();
        column[0]=temp[(k-1)*6+1];
        column[1]=temp[(k-1)*6+2];
        column[2]=temp[(k-1)*6+3];
        column[3]=temp[(k-1)*6+4];
        int j=(int)column.to_ulong();
        int num=S[9-k][i][j];
        
        bitset<4> SB(num);
        result[(k-1)*4]=SB[0];
        result[(k-1)*4+1]=SB[1];
        result[(k-1)*4+2]=SB[2];
        result[(k-1)*4+3]=SB[3];
    }
    bitset<32> final_result;
    
    for(int i=31;i>=0;i--)
    {
        final_result[i]=result[32-P[31-i]];
    }//p iteration
    
    return final_result;
}
void getip(const bitset<64>& plaintext)
{
    ifstream infile("ip.txt");
    int num;
    int i=63;
    while(infile>>num)
    {
        IP[i]=plaintext[64-num];
        i--;
    }
    infile.close();
    for(int i=0;i<=31;i++)
    {
        Right[0][i]=IP[i];
        Left[0][i]=IP[i+32];
    }
}

void iterate(const int n,bitset<32>* myleft,bitset<32>* myright)
{
    
    for(int i=0;i<=31;i++)
        myleft[n][i]=myright[n-1][i];
    myright[n]=(myleft[n-1]^func(n,myleft,myright));
    cout<<"第"<<n<<"次:"<<"Left: "<<Left[n]<<" Right: "<<Right[n]<<endl;
    
}
void initialize()
{
    ifstream infile("E.txt");
    int i=0;
    int num;
    while(infile>>num)
    {
        E[i]=num;
        i++;
    }
    infile.close();
    infile.open("Sbox.txt");
    for(int k=1;k<=8;k++)
    {
        for(int i=0;i<=3;i++)
            for(int j=0;j<=15;j++)
            {
                infile>>num;
                S[k][i][j]=num;
            }
    }
    infile.close();
    infile.open("P.txt");
    for(int i=0;i<=31;i++)
    {
        infile>>num;
        P[i]=num;
    }
    infile.close();
    infile.open("IP_1.txt");
    for(int i=0;i<=63;i++)
    {
        infile>>num;
        IP_1[i]=num;
    }
    infile.close();

}
#endif /* function_h */
