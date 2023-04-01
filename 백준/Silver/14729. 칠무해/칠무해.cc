#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
int a[100001];
int main() {
	int n, x, y;
	cin >> n;
	while (n--) {
		scanf("%d.%d", &x, &y);
		a[x * 1000 + y]++;
	}
	for (int i = 0, c = 0; i <= 100000; i++) {
		while (a[i]) {
			--a[i], ++c;
			printf("%d.%03d\n", i / 1000, i % 1000);
			if (c == 7) return 0;
		}
	}
	return 0;
}