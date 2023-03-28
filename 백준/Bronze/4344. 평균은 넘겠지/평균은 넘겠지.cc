#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
int main() {
	int n;
	double x;
	cin >> n;
	while (n--) {
		double sum = 0, cnt = 0;
		cin >> x;
		vector<int>v(x);
		for(int i=0; i<x; i++) {
			cin >> v[i];
			sum += v[i];
		}
		sum = sum / x;
		for (int i = 0; i < x; i++) {
			if (v[i] > sum) {
				cnt++;
			}
		}
		cout << fixed << setprecision(3) << cnt * 100 / x<< "%" << "\n";
	}
}