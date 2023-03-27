#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
	int n, x;
	double sum = 0;
	vector<double>v;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		v[i] =(v[i]*100)/ v.back();
		sum += v[i];
	}
	cout << fixed << setprecision(5) << sum / n;
}