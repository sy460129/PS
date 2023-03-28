#include <iostream>
#include <stack>
using namespace std;
int main() {
	int N;
	cin >> N;
	int* b = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> b[i];
	}
	stack<int> s;
	long long cnt = 0;
	for (int i = 0; i < N; i++) {
		while (!s.empty() && s.top() <= b[i]) {
			s.pop();
		}
		s.push(b[i]);
		cnt += s.size() - 1;
	}
	cout << cnt << "\n";
}
