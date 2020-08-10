#include<bits/stdc++.h>
using namespace std;
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int r;
	cin >> r;
	if (r >= 75 && r <= 85) {
		for (int j = 0; j <= r; j++) {
			int xmax = sqrt(r * r - j * j);
			for (int i = 0; i >= -1 * xmax; i--) {
				cout << "(" << i << "," << j << ")" << ",";
			}
		}
		cout << endl;
	}
	else cout << "Give Integer between 75 to 85 as input" << endl;
	return 0;
}
