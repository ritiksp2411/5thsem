#include <bits/stdc++.h>
using namespace std;
char sign[10000];
int resultwewant;
void printexp(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << sign[i] << " " << v[i] << " ";
    }
    cout<< endl;
}
void result(vector<int> v,int k, int n ,int r){
    int temp=r;
    if(k==n){
        if(r==resultwewant) printexp(v);
    }
    else{
        r+=v[k];
        sign[k]='+';
        result(v,k+1,n,r);
        temp-=v[k];
        sign[k]='-';
        result(v,k+1,n,temp);
    }
}
int main(){
    cout << "Enter the number of elements" << endl;
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    cout << "Give final result" << endl;
    cin >> resultwewant;
    result(v,0,n,0);
	return 0; 
} 
