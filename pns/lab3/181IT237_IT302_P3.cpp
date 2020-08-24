#include<bits/stdc++.h>
using namespace std;
int comb(int n,int k){  
    if (k == 0 || k == n) return 1;  
    return comb(n - 1, k - 1) + comb(n - 1, k);  
}
int main() {
    ofstream myfile;
    myfile.open("181IT237_IT302_P2_Output_TC6.txt");
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
    cout << "Here I printed the intermediate value as i : i ,comb(i,r) ,comb(m,i) ,sum of both" << endl;
    myfile << "Here I printed the intermediate value as i : i ,comb(i,r) ,comb(m,i) ,sum of both" << endl;
    for(int i=0; i<=n; i++){
        if(i>=r && i<=m){
            cout << "i=" << i << " " << comb(i,r) << " ";
            cout << comb(m,i) << " ";
            cout << comb(i,r)*comb(m,i) << endl;
            sum+=comb(i,r)*comb(m,i);
            myfile << "i=" << i << " " << comb(i,r) << " ";
            myfile << comb(m,i) << " ";
            myfile << comb(i,r)*comb(m,i) << endl;
        }
        else{
            cout << "i="<< i << " Invalid Input"<< endl;
            myfile << "i=" << i << " Invalid Input" << endl;
        }
    }
    if(sum==0){
        cout << "Invalid Input"<< endl;
        myfile << "Invalid Input";
    }
    else{
        cout << "The value of C: "<< (double)c/sum << endl;
        myfile << "The value of C: "<< (double)c/sum;
    }
    myfile.close();
	return 0;
}
