#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

int tokenCount(string s,char sep)
{
    int cantSep= charCount(s,sep);
    int i=1, posSep, posSep2=0;
    string cadToken;
    int contToken=0;
    while (i<=cantSep){
        posSep= indexOfN(s,sep,i);
        cadToken=substring(s,posSep2,posSep);
        if(!isEmpty(cadToken)){
            contToken+=1;
        }
        posSep2=posSep+1;
        //cout<<cadToken<<endl; muestra los tokens
        cadToken="";
        i++;
    }
    // cuando ya no existe el separador
    i-=1;
    if (cantSep==0|| i==cantSep){
        int l= length(s);
        posSep=l;
        cadToken= substring(s,posSep2,posSep);
        if(!isEmpty(cadToken))contToken+=1;
        //cout<<cadToken<<endl;// muestra el ultimo token
    }
    return contToken;

}

void addToken(string& s,char sep,string t)
{
}

string getTokenAt(string s,char sep, int i)
{
   return "";
}

void removeTokenAt(string& s,char sep, int i)
{
}

void setTokenAt(string& s,char sep, string t,int i)
{
}

int findToken(string s,char sep, string t)
{
   return 0;
}

#endif
