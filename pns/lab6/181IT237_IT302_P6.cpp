#include<bits/stdc++.h>
using namespace std;
int main() {
    ofstream myfile;
    myfile.open("181IT237_IT302_P6_Output_TC6.txt");
    int x=3;  
    int y=3;
    vector<int> xs(x),ys(y);
    cout << "Enter the values of x ";
    for(int i=0; i<x; i++){
        cin >> xs[i];
    }
    cout << "Enter the values of y ";
    for(int i=0; i<y; i++){
        cin >> ys[i];
    }
    vector<vector<double>> v(x,vector<double>(y));
    cout << "Enter the data of the table column wise because x is row and y is column in my code ";
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            double p;
            cin >> p;
            if(p>1){
                cout << "Invalid Input"<< endl;
                myfile << "Invalid Input";
                myfile.close();
                return 0;
            }
            else v[i][j]=p;
        }
    }
    vector<double> marx(x),mary(y);
    for(int i=0; i<x; i++){
        double sum=0;
        for(int j=0; j<y; j++){
            sum+=v[i][j];
        }
        marx[i]=sum;
    }
    for(int i=0; i<y; i++){
        double sum=0;
        for(int j=0; j<x; j++){
            sum+=v[j][i];
        }
        mary[i]=sum;
    }
    double meanx=0;
    for(int i=0; i<x; i++){
        meanx+=xs[i]*marx[i];
    }
    cout << "Mean of X is : " << meanx << endl;
    myfile << "Mean of X is : " << meanx << endl;
    double meany=0;
    for(int i=0; i<y; i++){
        meany+=ys[i]*mary[i];
    }
    cout << "Mean of Y is : " << meany << endl;
    myfile << "Mean of Y is : " << meany << endl;
    double gx=0;
    for(int i=0; i<xs.size(); i++){
        for(int j=0; j<ys.size(); j++){
            gx+=v[i][j]*(xs[i]*ys[j]);
            cout << gx << " ";
        }
    }
    cout << "Value G(x,y)=XY or E(XY) is : " << gx << endl;
    myfile << "Value G(x,y)=XY or E(XY) is : " << gx << endl;
    cout << "Covariance of the X and Y is : " << gx-meanx*meany << endl;
    myfile << "Covariance of the X and Y is : " << gx-meanx*meany << endl;
    myfile.close();
	return 0;
}