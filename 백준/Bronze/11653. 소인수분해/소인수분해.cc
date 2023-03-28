#include<iostream>
#include<string>
using namespace std;
int main() {
	int N;
	cin >> N;
	int max = 2;

	while (1) {
		if (N == 1) {
			return 0;
		}
		if (N % max == 0) {
			cout << max << endl;
			N /= max;
		}
		else {
			max += 1;
		}
		if (N == max) {
			cout << max;
			break;
		}
	}
}