#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	vector<int> v;
	int N, M, K, A;
	int m = 0, count = 1;
	cin >> N;
	cin >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> A;
		v.push_back(A);
	}
	sort(v.begin(), v.end());
	for(auto& e : v){
		e = v.back();
		m += e;
		if (m >= M * K) {
			cout << count;
			return 0;
		}
		else{
			count += 1;
		}
		v.pop_back();
	}
	cout << "STRESS";
}