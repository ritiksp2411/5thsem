#include<bits/stdc++.h>
using namespace std;
int main() {
    ofstream myfile;
    myfile.open("181IT237_IT302_P5_Output_TC3.txt");
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
    double meanx=0;
    for(int i=0; i<ax.size(); i++){
        meanx+=ax[i]*marx[i];
    }
    double meany=0;
    for(int i=0; i<ay.size(); i++){
        meany+=ay[i]*mary[i];
    }
    double gx=0;
    for(int i=0; i<ax.size(); i++){
        for(int j=0; j<ay.size(); j++){
            gx+=v[i][j]*( 2*ax[i]*ax[i] + ay[j]*ay[j] + 2*ax[i]*ay[j])
        }
    }
    myfile.close();
	return 0;
}


// Ux= sum for all x ( x * marginal(x) )
// Uy= sum for all y ( y * marginal(y) )

// sum for all x,y ==> g (X, Y) = 2X^2 +Y^2 +2XY * f(x,y)

// void sum(int a,int b){
//     int avg=a+b;
//     int sum=avg;
//     avg=avg/2;
//     cout << avg << " " << sum ;
// }