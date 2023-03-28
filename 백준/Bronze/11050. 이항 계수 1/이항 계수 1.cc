#include<iostream>
#include<string>
using namespace std;
int main() {
	int N, K;
	cin >> K >> N;
    int a = 1;
    int b = 1;
    for (int i = 1; i <= N; i++) {
        a *= K;
        K--;
    }
    for (int i = 1; i <= N; i++) {
        b *= i;
    }
    cout << a / b;
}