#include<bits/stdc++.h>
using namespace std;
int comb(int n,int k){  
    if (k == 0 || k == n) return 1;  
    return comb(n - 1, k - 1) + comb(n - 1, k);  
}
int main() {
    ofstream myfile;
    myfile.open("181IT237_IT302_P4_Output_TC6.txt");
	cout << "Enter n: " << endl;
    int n;
    cin >> n;
    if(n<=0){
        cout << "Invalid Input"<< endl;
        myfile << "Invalid Input";
        myfile.close();
        return 0;
    }
    cout << "Enter x: " << endl;
    int x;
    cin >> x;
    if(x<=0){
        cout << "Invalid Input"<< endl;
        myfile << "Invalid Input";
        myfile.close();
        return 0;
    }
    cout << "Enter y: " << endl;
    int y;
    cin >> y;
    if(y<=0){
        cout << "Invalid Input"<< endl;
        myfile << "Invalid Input";
        myfile.close();
        return 0;
    }
    cout << "Enter z: " << endl;
    int z;
    cin >> z;
    if(z<=0){
        cout << "Invalid Input"<< endl;
        myfile << "Invalid Input";
        myfile.close();
        return 0;
    }
    cout << "Joint probability function is equal to : (xCi)*(zCj)*(yC(n-i-j))/((x+y+z)Cn) " << endl;
    myfile << "Joint probability function is equal to : (xCi)*(zCj)*(yC(n-i-j))/((x+y+z)Cn) " << endl;
    vector<vector<double>> v(n+1,vector<double>(n+1));
    int den=comb(x+y+z,n);
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i<=x && j<=z && (n-i-j)<=y && (n-i-j)>=0){
                int ft=comb(x,i);
                int st=comb(z,j);
                int tt=comb(y,n-i-j);
                
                v[i][j]=(double)(ft*st*tt)/den;
            }
            else v[i][j]=0;
        }
    }
    vector<double> marx(n+1),marz(n+1);
    for(int i=0; i<=n; i++){
        double sum=0;
        for(int j=0; j<=n; j++){
            sum+=v[i][j];
        }
        marx[i]=sum;
    }
    for(int i=0; i<=n; i++){
        double sum=0;
        for(int j=0; j<=n; j++){
            sum+=v[j][i];
        }
        marz[i]=sum;
    }
    cout << "Joint Probability Function table: f(x,z) where 1st row is where x=0 and z varies from 0 to n" << endl;
    myfile << "Joint Probability Function table: f(x,z) where 1st row is where x=0 and z varies from 0 to n" << endl;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cout << "|  " << v[i][j] << "  ";
            myfile << "|  " << v[i][j] << "  ";
        }
        cout << endl;
        myfile << endl;
    }
    cout << "Marginal distribution of X alone : " << endl;
    myfile << "Marginal distribution of X alone : " << endl;
    for(int i=0; i<=n; i++){
        cout << marx[i] << " ";
        myfile << marx[i] << " ";
    }
    cout << endl;
    myfile << endl;
    cout << "Marginal distribution of Z alone : " << endl;
    myfile << "Marginal distribution of Z alone : " << endl;
    for(int i=0; i<=n; i++){
        cout << marz[i] << " ";
        myfile << marz[i] << " ";
    }
    myfile.close();
	return 0;
}
