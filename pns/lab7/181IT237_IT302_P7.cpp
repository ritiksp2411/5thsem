#include<bits/stdc++.h>
using namespace std;
int comb(int n,int k){  
    if (k == 0 || k == n) return 1;  
    return comb(n - 1, k - 1) + comb(n - 1, k);  
}
double power(double a, double b){
    double temp=a;
    for(int i=0; i<b-1; i++){
        a=a*temp;
    }
    return a;
}
int main(){
	cout << "Enter A: " << endl;
    int a;
    cin >> a;
    if(a<=0 && a>100){
        cout << "Invalid Input"<< endl;
        return 0;
    }
    cout << "Enter B: " << endl;
    int b;
    cin >> b;
    if(b<=0){
        cout << "Invalid Input"<< endl;
        return 0;
    }
    cout << "Enter N: " << endl;    
    int n;
    cin >> n;
    if(n<b){
        cout << "Invalid Input"<< endl;
        return 0;
    }
    cout << "Probability formula: NCB * (A/100)^B * (1-A/100)^(N-B)"<< endl;
    int NCB=comb(n,b);
    double ans=(double)NCB;
    ans=ans*power((double)a/100,b);
    ans=ans*power((double)(100-a)/100,n-b);
    cout << "Required Probability is " << ans << endl;
	return 0;
}
