#include<iostream>
#include<string>
using namespace std;
int main() {
	int T,R;
	string S;
	cin >> T;

	for (int k = 0; k < T; k++) {
		cin >> R >> S;
		for (int i = 0; i < S.size(); i++) {
			for (int j = 0; j < R; j++) {
				cout << S[i];
			}
		}
		cout << "\n";
	}
}