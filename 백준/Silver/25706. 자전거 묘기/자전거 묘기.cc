#include <iostream>
#include <vector>
using namespace std;
int dp[200001];
int arr[200001];
vector<int>v;
bool c;
int main() {
	int n, t;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		c = true;
		if (dp[i] == 0) {
			for (int j = i; j <= n; j += (arr[j] + 1)) {
				if (dp[j] != 0){
					c = false;
					t = dp[j];
					break;
				}	
				v.push_back(j);
			}
			if (!c) {
				int k = 1;
				while (!v.empty()) {
					dp[v.back()] = t + k;
					k++;
					v.pop_back();
				}
			}
			else {
				t = v.size();
				while (!v.empty()) {
					dp[v.back()] = t - v.size() + 1;
					v.pop_back();
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << dp[i] << " ";
	}
}