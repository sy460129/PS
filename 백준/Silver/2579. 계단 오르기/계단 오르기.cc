#include<iostream>
using namespace std;
int score[301];
int arr[301];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i <n; i++) {
		cin >> arr[i];
	}
	score[0] = arr[0];
	score[1] = arr[0] + arr[1];
	score[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
	for (int i = 3; i < n; i++) {
		score[i] = max(score[i - 2] + arr[i], arr[i] + arr[i - 1] + score[i - 3]);
	}
	cout << score[n-1];
}