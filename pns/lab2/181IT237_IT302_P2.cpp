#include<bits/stdc++.h>
using namespace std;
int main() {
	cout << "Enter the number of inspectors: " << endl;
    int n;
    cin >> n;
    ofstream myfile;
    myfile.open("181IT237_IT302_P2_Output_TC1.txt");
    string a[n];
    cout << "Enter the names: " << endl;
    for(int i=0; i<n; i++){
        cin>>a[i];
        if((a[i][0]>='a' && a[i][0]<='z') || (a[i][0]>='A' && a[i][0]>='Z')) continue;
        else{
            myfile << "Invalid input";
            cout << "Invalid input" << endl;
            return 0;
        } 
    }
    int per[n],mistake[n];
    int count=0;
    cout << "Enter the percentage: "<< endl;
    for(int i=0; i<n; i++){
        cin >>per[i];
        count+=per[i];
        if(count>=100 && i!=n-1){
            myfile << "Invalid input";
            cout << "Invalid input" << endl;
            return 0; 
        } 
    }
    cout << "Enter the number of packages after which they will commit the mistake: "<< endl;
    for(int i=0; i<n; i++) cin >>mistake[i];
    cout << "Enter the inpector name for which we want to know the probability: " << endl;
    string target;
    cin >> target;
    int index=0;
    for(int i=0; i<n; i++){
        if(target==a[i]){
            index=i;
            break;
        }
    } 
    double prob=0;
    double total=0;
    for(int i=0; i<n; i++){
        total+=(double)per[i]/mistake[i];
    }
    prob=(double)per[index]/mistake[index];
    myfile << "Reqiured Probability: "<< (double)prob/total;
    cout << "Reqiured Probability: "<< (double)prob/total << endl;
    myfile.close();
	return 0;
}
