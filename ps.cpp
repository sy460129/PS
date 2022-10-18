#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t, n; cin >> t;
	while (t--) {
		bool c = false, ch = false;
		long long ans = 0, res, cnt = 2147483647, k = 1, l = 0, j = 0, p = 0;
		cin >> n;
		int* arr = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			ans += arr[i];
		}
		while (1) {
			bool check = true;
			res = ans;
			if (res % k == 0) {
				res /= k;
				p = 0, l = 0, j = 0;
				for (int i = 0; i < n; i++) {
					p += arr[i];
					l++;
					if (p == res) {
						j = max(j, l);
						l = 0, p = 0;
					}
					else if (p > res) {
						check = false;
						break;
					}
				}
                if (check) {
		    		ch = true;
		    		cnt = min(cnt, j);
		    	}
			}
			k++;
            if(k>ans) break;
		}
		ch ? cout << cnt << "\n" : cout << n << "\n";
	}
}