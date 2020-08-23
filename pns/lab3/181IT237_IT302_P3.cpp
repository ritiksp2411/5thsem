#include<bits/stdc++.h>
using namespace std;
int comb(int n,int k){  
    if (k == 0 || k == n) return 1;  
    return comb(n - 1, k - 1) + comb(n - 1, k);  
}
int main() {
    ofstream myfile;
    myfile.open("181IT237_IT302_P2_Output_TC1.txt");
	cout << "Enter r: " << endl;
    int r;
    cin >> r;
    if(r<=0){
        cout << "Invalid Input"<< endl;
        myfile << "Invalid Input";
        myfile.close();
        return 0;
    }
    cout << "Enter m: " << endl;
    int m;
    cin >> m;
    if(m<=0 || r>m){
        cout << "Invalid Input"<< endl;
        myfile << "Invalid Input";
        myfile.close();
        return 0;
    }
    cout << "Enter n: " << endl;
    int n;
    cin >> n;
    if(n<=0){
        cout << "Invalid Input"<< endl;
        myfile << "Invalid Input";
        myfile.close();
        return 0;
    }
    int c=1;
    int sum=0;
    for(int i=r; i<=m; i++){
        sum+= comb(i,r)*comb(m,i);
    }
    cout << "The value of C: "<< (double)c/sum << endl;
    myfile << "The value of C: "<< (double)c/sum;
    myfile.close();
	return 0;
}
