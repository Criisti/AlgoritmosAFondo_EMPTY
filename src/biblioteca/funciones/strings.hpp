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
    int contLetrasIguales=0, cont= length(toSearch),j=0;

    for (int i = 0; i<= length(s) ; ++i) {
        if(s[i]==toSearch[j]){
            contLetrasIguales+=1;
            j++;

            if(contLetrasIguales== cont&& s[i+1]==' '|| s[i]=='\0'){
                    if(s[i-cont]==' '){
                        return i-cont+1;
                    }else {
                        // solo para el caso de que toSearch sea la ultima palabra
                        return i-cont;
                    }
            }
        }else{
            j=0;
            contLetrasIguales=0;
        }
    }
    if(contLetrasIguales==0||j==0)return -1;
}

int indexOf(string s,string toSearch,int offset) // 1.1.1.8
{
    int contLetrasIguales=0, cont= length(toSearch),j=0;

    for (int i = offset; i<= length(s) ; ++i) {
        if(s[i]==toSearch[j]){
            contLetrasIguales+=1;
            j++;

            if(contLetrasIguales== cont&& s[i+1]==' '|| s[i]=='\0'){
                if(s[i-cont]==' '){
                    return i-cont+1;
                }else {
                    // solo para el caso de que toSearch sea la ultima palabra
                    return i-cont;
                }
            }
        }else{
            j=0;
            contLetrasIguales=0;
        }
    }
    if(contLetrasIguales==0||j==0)return -1;
}

int lastIndexOf(string s,char c)
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

string intToString(int i)//1.1.1.15 muy raro el caso cuando el primer elemento es 0
{
   int cantEntero= digitCount(i);
   int j=0,resto;
   string cadEnteros;
   char numLetra;
   while(j<cantEntero){
       resto=i%10;
       i/=10;
       numLetra= intToChar(resto);
       cadEnteros=cadEnteros + numLetra;
       j++;
   }
   string cadEnterosInvertida;
    for (int k = length(cadEnteros)-1; k>=0; --k) { // -1 para omitir el 1 \0 de cadEntros
        cadEnterosInvertida+=cadEnteros[k];
    }
    return cadEnterosInvertida;
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

string stringToString(string& s)
{
    string mismaCadena;
    mismaCadena=s;
    return mismaCadena;
}

string doubleToString(double d)//1.1.1.21
{
/*    // funciona con mayor cantidad de enteros o iguales a los decimales

    int cadEnteros=digitCount(d); // cuantos enteros tiene //3
    int parEntera=d; // los enteros //123
    int parEntera2=parEntera; //123
    int  decimal;

    while(cadEnteros>0){
        d*=10;
        parEntera*=10;
        cadEnteros--;
    }
    int deci=d;
    decimal = abs(parEntera -deci);

    return intToString(parEntera2)+","+ intToString(decimal);*/
    string cad= to_string(d);
    return cad;
}

double stringToDouble(string s)//1.1.1.22
{
    int posComa = indexOf(s,'.');
    string entero,decimal;
    for (int i = 0; s[i]!='.'; ++i) {
        entero += s[i];
    }
    for (int i = posComa+1; s[i]!='\0' ; ++i) {
        decimal+=s[i];
    }
    double enteroEntero= stringToInt(entero);
    // double enteroo= enteroEntero;
    int entDecimal= stringToInt(decimal);
    double deci=entDecimal;
    int  auxDeci= digitCount(entDecimal);
    while (auxDeci>0){
        deci/=10;
        auxDeci--;
    }
    return enteroEntero+deci;
    /* opcion b
     *double num = stod(s);
     * return num;
     * */
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
    }
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

bool contains(string s,char c)//ok
{
    for(int i = 0; s[i]!='\0'; i++){
        if (s[i]== c)return true;
    }
    return false;
}

string replace(string s,char oldChar,char newChar)
{
    for(int i = 0; s[i]!='\0'; i++){
        if (s[i]== oldChar)s[i]=newChar;
    }
    return s;
}

string insertAt(string& s,int pos,char c)
{
    string parte1=substring(s,0,pos), parte2=substring(s,pos, length(s));
    return parte1+c+parte2;
}

string removeAt(string& s,int pos)
{
    string parte1=substring(s,0,pos), parte2=substring(s,pos+1, length(s));
    return parte1+parte2;
}

string ltrim(string s)
{
    int i=0;
    while (s[i]==' '){
        i++;
    }
    return substring(s,i);
}

string rtrim(string s)
{
    string cadRev, cadAux,cadFinal;
    // invierto la cadena con espacio
    for (int i= length(s)-1; i >=0 ; --i) {
        cadRev+=s[i];
    }
    cadAux= ltrim(cadRev);// cadena invertida sin espacios
    // vuelvo a invertir la cadea sin espacios
    for (int i= 0; i < length(cadAux) ; ++i) {
        cadFinal+=s[i];
    }

    return cadFinal;

}

string trim(string& s)
{
    return rtrim(ltrim(s));
}

string replicate(char c,int n) {
    string cad;
    while(n>0){
        cad+=c;
        n--;
    }
    return cad;
}

string spaces(int n)
{
    char c=' ';
    return replicate(c,n);
}

string lpad(string& s,int n,char c)
{
    int i= length(s);
    string completo;
    while(i<n){
        completo+=c;
        i++;
    }
    return completo+s;
}

string rpad(string s,int n,char c)
{
    while(length(s)<n){
        s+=c;
    }
    return s;
}

string cpad(string& s,int n,char c)
{
    string ss= lpad(s,n/2+2,c);
    return rpad(ss,n,c);
}

bool isDigit(char c)
{
    return (c>=48&&c<=57);
}

bool isLetter(char c)
{
    return ((c>=65&&c<=90)||(c>=97&&c<=122));
}

bool isUpperCase(char c)//ok
{
    // uzando ascii
    return (c>=65 && c<=90);
}

bool isLowerCase(char c)//ok
{
    return (c>=97&&c<=122);
}

char toUpperCase(char c)
{
    if(isLowerCase(c)){
        return c-=32;
    }else{
        return c;
    }

}

char toLowerCase(char c)
{
    if(isUpperCase(c)){
        return c+=32;
    }else{
        return c;
    }
}

string toUpperCase(string s)
{
    string cadMayuscula;
    for (int i = 0; s[i]!='\0'; ++i) {
        cadMayuscula+= toUpperCase(s[i]);
    }
    return cadMayuscula;
}

string toLowerCase(string s)
{
    string cadMinuscula;
    for (int i = 0; s[i]!='\0'; ++i) {
        cadMinuscula+=  toLowerCase(s[i]);
    }
    return cadMinuscula;
}

int cmpString(string& a,string& b)
{
    if (length(a)< length(b))return -1;
    if (length(a)> length(b))return 1;
    if (length(a)== length(b))return 0;
}

int cmpDouble(double a,double b)
{
    if(a<b)return -1;
    if(a>b)return 1;
    if (a==b)return 0;
}

#endif
