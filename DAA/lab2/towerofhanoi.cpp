#include <bits/stdc++.h> 
using namespace std; 
  
void towerofhanoi(int n, char from,char to, char mediater){
    if (n == 1){
        cout << "Move disk 1 from rod " << from << " to rod " << to<<endl;  
        return;  
    }  
    towerofhanoi(n - 1, from, mediater, to);  
    cout << "Move disk " << n << " from rod " << from <<" to rod " << to << endl;  
    towerofhanoi(n - 1, mediater, to, from);  
}  

int main(){ 
    int n;
    cin>>n; 
    towerofhanoi(n, 'S', 'T', 'I');  
    return 0;  
}  