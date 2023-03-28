#include<iostream>
#include<string>
using namespace std;
int main() {
	int N, c = 0;
	cin >> N;
	N = 1000 - N;
	while (N/500!=0) {
		N -= 500;
		c += 1;
	}
	while (N / 100 != 0) {
		N -= 100;
		c += 1;
	}
	while (N / 50 != 0) {
		N -= 50;
		c += 1;
	}
	while (N / 10 != 0) {
		N -= 10;
		c += 1;
	}
	while (N / 5 != 0) {
		N -= 5;
		c += 1;
	}
	while (N / 1 != 0) {
		N -= 1;
		c += 1;
	}
	cout << c;
}