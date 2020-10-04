#define N 4 
#include <bits/stdc++.h>
using namespace std;
bool isSafe(int board[N][N], int row, int col){
	int i, j; 
	for (i = 0; i < col; i++) 
		if (board[row][i]) return false;
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
		if (board[i][j]) return false;
	for (i = row, j = col; j >= 0 && i < N; i++, j--) 
		if (board[i][j]) return false; 

	return true; 
}
bool solveNQUtil(int board[N][N], int col){
	if (col >= N) return true;
	for (int i = 0; i < N; i++) {
		if (isSafe(board, i, col)) {
			board[i][col] = 1;
			if (solveNQUtil(board, col + 1)) return true;
			board[i][col] = 0; 
		} 
	}
	return false; 
} 

void print(vector<int> q){
	for(int i=1; i<q.size(); i++) cout << q[i] << " ";
}

void nqueen(vector<int> q,int i){
	if(i==q.size()-1){
		print(q);
		return ;
	}
	for(int j=1; j<q.size(); j++){
		int valid=true;
		for(int k=1; k<=i-1; k++){
			if(q[k]==j || abs(q[k]-q[i])==abs(k-i)){
				valid=false; 
				break;
			}
		}
		if(valid==true){
			q[i]=j;
			nqueen(q,i+1);
		}
	}
}
int main(){
	int board[N][N] = { { 0, 0, 0, 0 }, 
						{ 0, 0, 0, 0 }, 
						{ 0, 0, 0, 0 }, 
						{ 0, 0, 0, 0 } }; 

	if (solveNQUtil(board, 0) == false) { 
		printf("Solution does not exist"); 
		return 0; 
	}
	vector<int> q(5);
	nqueen(q,1); 
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < N; j++) 
			printf(" %d ", board[i][j]); 
		printf("\n"); 
	} 
	return 0; 
} 

