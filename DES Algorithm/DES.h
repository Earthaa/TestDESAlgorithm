//
//  DES.h
//  DES Algorithm
//
//  Created by Yi Zhou on 2017/4/30.
//  Copyright © 2017年 Yi Zhou. All rights reserved.
//

#ifndef DES_h
#define DES_h
#include "Encrypt.h"
#include "transfer.h"
#include "key.h"
#include "descrypt.h"
getkey *a=new getkey();
Encrypt *enc=new Encrypt();
Descrypt *des=new Descrypt();
void DoEncrypt(string text)
{
    string myhex=string_to_hex(text);
    string tmp="0x";
    for(int i=0;;i++)
    {
        if(16*i+18<=myhex.size())
        {
            tmp+=myhex.substr(16*i+2,16);
            enc->GetCiphertext(string_to_bit(tmp));
            cout<<hex<<myCiphertext.to_ullong()<<endl;
            tmp="0x";
        }
        else
        {
            tmp+=myhex.substr(16*i+2,myhex.size()-16*i-2);
            break;
        }
        
    }
    if(18-tmp.size()>=4)
    {
        tmp+="0D0A";
        while (tmp.size()<18) {
            tmp+="00";
        }
    }
    else if (18-tmp.size()==2)
    {
        tmp+="0D";
    }
    enc->GetCiphertext(string_to_bit(tmp));
    cout<<hex<<myCiphertext.to_ullong()<<endl;

}
void DoDescrypt(string text)
{
    des->GetPlaintext(string_to_bit(text));
    cout<<hex<<myDeciphertext.to_ullong()<<endl;

}
void DES(string key,string text,bool code)
{
    initialize();
    a->getmykey(string_to_bit(key));
    if(code==true)
        DoEncrypt(text);
    else
        DoDescrypt(text);
}


#endif /* DES_h */
