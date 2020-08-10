#include<bits/stdc++.h>
using namespace std;
int main() {
	int r;
	cin >> r;
	ofstream myfile;
	myfile.open("output.txt");
	if (r >= 75 && r <= 85) {
		for (int j = 0; j < r; j++) {
			int xmax = sqrt(r * r - j * j);
			if(xmax*xmax==r * r - j * j) xmax--;
			for (int i = 0; i >= -1 * xmax; i--) {
				myfile << "(" << i << "," << j << ")" << ",";
				cout << "(" << i << "," << j << ")" << ",";
			}
		}
		cout << endl;
	}
	else{
		myfile << "Give Integer between 75 to 85 as input(Invalid Input)" << endl;
		cout << "Give Integer between 75 to 85 as input(Invalid Input)" << endl;
	}
	myfile.close();
	return 0;
}
