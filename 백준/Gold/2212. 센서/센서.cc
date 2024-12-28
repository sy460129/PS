#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q;
vector<int> v;
int main() {
  int n, k, x, y, ans = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size() - 1; i++) {
    if (v[i] == v[i + 1])
      continue;
    else
      q.push(v[i + 1] - v[i]);
  }
  while (q.size() >= k) {
    ans += q.top();
    q.pop();
  }
  cout << ans;
}