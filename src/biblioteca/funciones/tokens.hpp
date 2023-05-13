#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

int tokenCount(string& s,char sep)
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

void addToken(string& s,char sep,string t) {
    s+=sep+t;
}

string getTokenAt(string s,char sep, int i)
{
    int cantTokens= tokenCount(s,sep);
    int posSep, posSep2=0;
    string cadToken;
    while(cantTokens>=0){
        if (cantTokens==i){
            posSep= indexOfN(s,sep,i+1);
            if (i==0){
                cadToken= substring(s,posSep2,posSep);
            }else{
                posSep2= indexOfN(s,sep,i);
                cadToken= substring(s,posSep2+1,posSep);
            }
        }
        cantTokens--;
    }
    return cadToken;
}

void removeTokenAt(string& s,char sep, int i) {

    if(i==0) {
        int posTokenEli = indexOfN(s, sep, i+1);//+1 para buscar el primero sep
        s= substring(s,posTokenEli+1);// +1 elimina el separador del inicio
    }else{
        int posTokenEli = indexOfN(s, sep, i);
        string sIni = substring(s, 0, posTokenEli);

        string TokenEli = getTokenAt(s, sep, i);
        int l = length(TokenEli);
        string sFin = substring(s, posTokenEli + l+1);// +1 para quedarse con el sep del token final
        s = sIni + sFin;
    }
}

void setTokenAt(string& s,char sep, string t,int i)
{
   if(i==0){
       string ss=s;
       s="";
       s=t+sep+ss;
   }else {
       int posToken= indexOfN(s,sep,i);
       string sA= substring(s,0,posToken);
       string sB= substring(s,posToken);
       s=sA+sep+t+sB;
   }
}

int findToken(string s,char sep, string t)
{
   int posTokens= tokenCount(s,sep);
   while(posTokens>=0){
       if(getTokenAt(s,sep,posTokens)==t)return posTokens;
       posTokens--;
   }
   if(posTokens==-1)return -1;
}

#endif
