#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int M, N, smallest = 0, count = 0, c = 0;
	cin >> M >> N;
	for (int i = N; i >= M; i--) {
		int x = sqrt(i);
		if (i==x*x) {
			smallest = i;
			count++;
			c += i;
		}
	}
	if (count == 0) {
		cout << -1;
		return 0;
	}
	cout << c << endl << smallest;
}