#include <iostream>
#include <cmath>
using namespace std;
int arr[1001][1001];
int main() {
	int n, m, ans = 0;
	string s;
	cin >> n >> m;
	for(int i =0 ; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++){
			arr[i][j] = s[j] - '0';
			if(arr[i][j] == 1){
				ans = 1;
			}
		}
	}
	for(int i = 1; i < n; i++){
		for(int j = 1; j < m; j++){
			if(arr[i][j] == 1 && arr[i - 1][j] != 0 && arr[i][j - 1] != 0 && arr[i - 1][j - 1] != 0){
				arr[i][j] = min(arr[i - 1][j], min(arr[i][j - 1], arr[i - 1][j - 1])) + 1;
			}
			ans = max(ans, arr[i][j]);
		}
	}
	cout << pow(ans,2);
}