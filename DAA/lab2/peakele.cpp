#include <bits/stdc++.h> 
using namespace std; 

void peakele(vector<int> &v, int s,int e){
    int mid=s+(e-s)/2;
    if(v[mid]>v[mid+1] && v[mid]>v[mid-1]){
        cout << v[mid];
        return;
    }
    if(v[mid]>v[mid+1] && v[mid]<v[mid-1]) peakele(v,s,mid);
    else peakele(v,mid,e);
    return;
}
int main(){ 
    int n;
    cin>>n; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    peakele(v,0,n-1);
    return 0;  
}  