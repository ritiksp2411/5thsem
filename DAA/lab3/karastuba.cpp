
#include<iostream> 
#include<stdio.h> 
string addbitstrings( string first, string second ){
    string result;
    int carry = 0; 
    for (int i = length-1 ; i >= 0 ; i--){
        int firstBit = first.at(i) - '0'; 
        int secondBit = second.at(i) - '0'; 
        int sum = (firstBit ^ secondBit ^ carry)+'0'; 
        result = (char)sum + result;  
        carry = (firstBit&secondBit) | (secondBit&carry) | (firstBit&carry); 
    }
    if (carry) result = '1' + result; 
    return result; 
} 

int multiplyiSingleBit(string a, string b){  
    return (a[0] - '0')*(b[0] - '0');  
} 

long int multiply(string X, string Y){
    if (n == 0) return 0; 
    if (n == 1) return multiplyiSingleBit(X, Y); 
  
    int fh = n/2;
    int sh = (n-fh); 
    string Xl = X.substr(0, fh); 
    string Xr = X.substr(fh, sh); 
    string Yl = Y.substr(0, fh); 
    string Yr = Y.substr(fh, sh); 
  
    long int P1 = multiply(Xl, Yl); 
    long int P2 = multiply(Xr, Yr); 
    long int P3 = multiply(addBitStrings(Xl, Xr), addBitStrings(Yl, Yr)); 
    return P1*(1<<(2*sh)) + (P3 - P1 - P2)*(1<<sh) + P2; 
} 
int main(){
    printf ("%ld\n", multiply("1100", "1010")); 
    return 0;
} 