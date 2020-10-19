#include<bits/stdc++.h>
using namespace std;
double power(double a, double b){
    double temp=a;
    for(double i=0; i<b-1; i++) a=a*temp;
    return a;
}
double factorial(double n){ 
    if (n == 0) return 1; 
    return n * factorial(n - 1); 
} 
  
int main(){
    ofstream myfile;
    myfile.open("181IT237_IT302_P8_Output_TC1.txt");
	cout << "Enter X: " << endl;
    double x;
    cin >> x;
    if(x<=0){
        cout << "Invalid Input"<< endl;
        myfile << "Invalid Input";
        myfile.close();
        return 0;
    }
    cout << "Enter Y: " << endl;
    double y;
    cin >> y;
    if(y<=0){
        cout << "Invalid Input"<< endl;
        myfile << "Invalid Input";
        myfile.close();
        return 0;
    }
    cout << "Probability formula: X^Y/(Y!)*(e^X)"<< endl;
    myfile << "Probability formula: X^Y/(Y!)*(e^X)"<< endl;
    double powerxy=power(x,y);
    double facty=factorial(y);
    double powere=power(2.71828,x);
    double ans= powerxy/(facty*powere);
    cout << ans << endl;
    myfile << ans << endl;
    myfile.close();
	return 0;
}
