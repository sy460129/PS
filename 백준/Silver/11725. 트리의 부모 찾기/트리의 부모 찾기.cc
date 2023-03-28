#include <iostream>
#include <vector>
using namespace std;
vector<int>v[100001];
int arr[100001];
void dfs(int n) {
	for (int i = 0; i < v[n].size(); i++) {
		if (arr[v[n][i]] == 0) {
			arr[v[n][i]] = n;
			dfs(v[n][i]);
		}
	}
}
int main(){
	int n, x, y, t;
	cin >> n;
	t = n;
	n--;
	while (n--) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	for (int i = 2; i <= t; i++) {
		cout << arr[i] << "\n";
	}
}