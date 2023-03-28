#include<iostream>
#include<string>
int arr[101];
using namespace std;
int main() {
	int n, x;
	arr[0] = 0;
	string s, large;
	cin >> n;
	while (n--) {
		int la = arr[0];
		cin >> x;
		for (int i = 1; i <= x; i++) {
			cin >> s >> arr[i];
			if (arr[i] > la) {
				large = s;
				la = arr[i];
			}
		}
		cout << large << "\n";
	}
}