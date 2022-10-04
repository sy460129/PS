#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int arr[1000001];
bool check, c;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	vector<long long>v;
	for (long long i = 2; i < 1000001; i++) {
		if (arr[i] == 0) {
			for (long long j = 2; j <= 1000001 / i; j++) {
				arr[i * j] = 1;
			}
		}
	}
	long long n;
	cin >> n;
	for (long long i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			check = true;
			if (arr[i] == 1 && i >= 4) {
				v.push_back(i);
				n/=i;
				i=1;
			}
		}
	}
	if(n!=1){
		for (long long i = 2; i <= sqrt(n); i++) {
			if (n % i == 0) {
				c = true;
				break;
			}
		}
	}
	if (!v.empty() && n!=1) {
		if(c){
			v.push_back(n);
		}
		else{
			long long x = v.back();
			v.pop_back();
			v.push_back(n * x);
		}
	}
	if (v.empty() && check == true) {
		cout << n << "\n";
	}
	else if (!v.empty()) {
		for (auto& e : v) {
			cout << e << " ";
		}
		cout << "\n";
	}
	else {
		cout << -1 << "\n";
	}
}