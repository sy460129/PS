#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		cout << a + b << "\n";
	}

}