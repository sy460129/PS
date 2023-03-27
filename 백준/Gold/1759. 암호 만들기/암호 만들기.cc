#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, ahdma = 0, wkdma = 0;
vector<char>v;
vector<char>vec;
bool check[16];
void dfs(int cnt) {
	if (vec.size() == n && ahdma >= 1 && wkdma >= 2) {
		for (auto& e : vec) {
			cout << e;
		}
		cout << "\n";
		return;
	}
	else if (vec.size() == n && (ahdma < 1 || wkdma < 2)) {
		return;
	}
	for (int i = cnt; i < m; i++) {
		if (!check[i]) {
			vec.push_back(v[i]);
			check[i] = true;
			if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
				ahdma++;
			}
			else {
				wkdma++;
			}
			dfs(i);
			if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
				ahdma--;
			}
			else {
				wkdma--;
			}
			vec.pop_back();
			check[i] = false;
		}
	}
}
void track(int cnt) {
	for (int i = 0; i < m; i++) {
		vec.push_back(v[i]);
		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
			ahdma++;
		}
		else {
			wkdma++;
		}
		check[i] = true;
		dfs(cnt + 1);
		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
			ahdma--;
		}
		else {
			wkdma--;
		}
		vec.pop_back();
	}
}
int main() {
	cin >> n >> m;
	v.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	track(0);
}