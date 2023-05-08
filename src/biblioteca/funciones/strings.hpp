#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int length(string s)
{
    int i=0;
    while (s[i]!='\0'){
        i++;
    }
   return i;
}

int charCount(string s,char c)
{
    int letraEncontrada=0;
    for (int i = 0;s[i]!= '\0'; ++i) {
        if (s[i]==c)letraEncontrada+=1;
    }
    return letraEncontrada;
}

string substring(string s,int d,int h)
{
    string subcad;
    for (int i = d; i < h; i++) {
        subcad += s[i];// concatena caracteres
    }
    return subcad;
}

string substring(string& s,int d) // &: usa el original de la cadena
{
   return substring(s,d, length(s));
}

int indexOf(string s,char c) // ok
{
    for(int i = 0; s[i]!='\0'; i++){
        if (s[i]== c)return i;
    }
    return -1;
}

int indexOf(string s,char c,int offSet) // ok
{
    for(int i=offSet; s[i]!='\0';i++){
        if(s[i]==c)return i;
    }
}

int indexOf(string s,string toSearch) // 1.1.1.7
{
   return 0;
}

int indexOf(string s,string toSearch,int offset) // 1.1.1.8
{

}

int lastIndexOf(string s,char c)// 1.1.1.9 Inversa 1.1.1.5
{
    for (int i= length(s);i>=0;i--){
        if(s[i]==c)return i;
    }
    return -1;
}

int indexOfN(string s,char c,int n)
{
    int i=0, aux=0;
    while(s[i]!='\0'){
        if(s[i]==c)aux++;
        if(aux==n) return i;
        i++;
    }
    if(aux==0)return -1;
    if(i== length(s) && n>aux)return length(s);
}

int charToInt(char c)
{
    //'0'=48 y '9'=57
    if (c>=48 && c<=57)return (c-48);
    // 'A'=65 y 'Z'=90 // 'A'=10 'Z'=35
    if(c>=65 && c<=90)return (c-65+10);
    //'a'=97 y 'z'=122
    if(c>=97 && c<=122)return (c-97+10);
}

char intToChar(int i)
{
    if (i>=0 && i<=9)return (i+48);
    // 'A'=65 y 'Z'=90 // 'A'=10 'Z'=35
    if(i>=10 && i<=36)return (i+65-10);
    //'a'=97 y 'z'=122 // En caso para minusculas 'a'=36 'a'=36
    //  if(c>=97 && c<=122)return (c+97-10);
}

int getDigit(int n,int i)
{
    while (i>0){
        n=n/10;
        i--;
    }
    return n%10;
}

int digitCount(int n)
{
    // Lo maximo que admite n son 10 digitos positivos
    int aux =0;
    while (n>0){
        n/=10;
        aux++;
    }
    return aux;
}

string intToString(int i)//1.1.1.15
{
   return "";
}

int stringToInt(string s,int b) // ok
{
// String -decimal
    if (b==10){
        int entero, enteroEnteros= charToInt(s[0]);
        // para pasar a decimal
        for (int i = 1; i < length(s); ++i) {
            entero= charToInt(s[i]);
            if (entero >9 && entero <36){// caso de ser una letra
                enteroEnteros=enteroEnteros*100+entero;
            }else{
                enteroEnteros = enteroEnteros*10+entero;
            }
        }
        return enteroEnteros;
    }

    // String_Binario - Decimal
    if (b==2){
        int bin=1, res=0,cambioNum;
        int i = 0,j= length(s)-1;
        while (s[i]!='\0'){
            cambioNum= charToInt(s[i]);
            // descarto los 0
            if (cambioNum==1){
                // 2^j
                while (j>0){
                    bin*=2;
                    j--;
                }
                res+=bin;// sumo los resultados
                bin=1;
            }
            i++;
            j= length(s)-1-i;

        }
        return res;
    }

    //String_Hexadecimal - Decimal
    if (b==16){
        int bin=1, res=0,cambioNum;
        int i = 0,j= length(s)-1;
        while (s[i]!='\0'){
            cambioNum= charToInt(s[i]);
            // descarto los 0
            if (cambioNum!=0){
                // 2^j
                while (j>0){
                    bin*=16;
                    j--;
                }
                res= res+bin*cambioNum;// sumo los resultados
                bin=1;
            }
            i++;
            j= length(s)-1-i;

        }
        return res;
    }
}

int stringToInt(string s) // ok
{
    int entero, enteroEnteros= charToInt(s[0]);
    // para pasar a decimal
    for (int i = 1; i < length(s); ++i) {
        entero= charToInt(s[i]);
        if (entero >9 && entero <36){// caso de ser una letra
            enteroEnteros=enteroEnteros*100+entero;
        }else{
            enteroEnteros = enteroEnteros*10+entero;
        }
    }
    return enteroEnteros;
}

string charToString(char c)
{
    string cadena;
    cadena=c;
    return cadena;
}

char stringToChar(string s)
{
    char letra;
    letra =s[0];
    return letra;
}

string stringToString(string s)
{
    string mismaCadena;
    mismaCadena=s;
    return mismaCadena;
}

string doubleToString(double d)//1.1.1.21
{
   return "";
}

double stringToDouble(string s)//1.1.1.22
{
   return 1.1;
}

bool isEmpty(string s)
{
    return s=="";
}

bool startsWith(string s,string x)
{
    int cont=0;
    for (int i = 0,t=0; x[i]!='\0'; ++i,t++) {
        if(x[i]==s[t])cont+=1;
    }
    if (cont== length(x)){
        return true;
    }else{
        return false;
    };
}

bool endsWith(string s,string x)
{
    int cont=0;
    for (int i= length(x),t= length(s); i >0 ; --i,t--) {
        if(x[i]==s[t])cont+=1;
    }
    if(cont== length(x)){
        return true;
    }else {
        return false;
    }
}

bool contains(string s,char c)
{
   return true;
}

string replace(string s,char oldChar,char newChar)
{
   return "";
}

string insertAt(string s,int pos,char c)
{
   return "";
}

string removeAt(string s,int pos)
{
   return "";
}

string ltrim(string s)
{
   return "";
}

string rtrim(string s)
{
   return "";
}

string trim(string s)
{
   return "";
}

string replicate(char c,int n)
{
   return "";
}

string spaces(int n)
{
   return "";
}

string lpad(string s,int n,char c)
{
   return "";
}

string rpad(string s,int n,char c)
{
   return "";
}

string cpad(string s,int n,char c)
{
   return "";
}

bool isDigit(char c)
{
   return true;
}

bool isLetter(char c)
{
   return true;
}

bool isUpperCase(char c)
{
   return true;
}

bool isLowerCase(char c)
{
   return true;
}

char toUpperCase(char c)
{
   return 'X';
}

char toLowerCase(char c)
{
   return 'X';
}

string toUpperCase(string s)
{
   return "";
}

string toLowerCase(string s)
{
   return "";
}

int cmpString(string a,string b)
{
   return 0;
}

int cmpDouble(double a,double b)
{
   return 0;
}

#endif
