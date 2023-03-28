#include<iostream>
using namespace std;
int arr[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		arr[x]++;
	}
	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < arr[i]; j++) {
			cout << i << "\n";
		}
	}
}