#include<iostream>
using namespace std;
int main() {
    int n;
    long long res = 2147483647, t;
    cin >> n;
    long long* arr = new long long[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int c = 0, f = 0, e = n - 1;
    while (1) {
        int mid = (f + e) / 2;
        if (arr[c] + arr[mid] >= 0) {
            e = mid - 1;
        }
        else if (arr[c] + arr[mid] < 0) {
            f = mid + 1;
        }
        if (abs(arr[c] + arr[mid]) < res) {
            if (c != mid) {
                res = abs(arr[c] + arr[mid]);
                if (arr[c] + arr[mid] < 0) {
                    t = -res;
                }
                else {
                    t = res;
                }
            }
        }
        if (f > e) {
            c++;
            f = 0, e = n - 1;
        }
        if (c == n || res == 0) {
            break;
        }
    }
    cout << t << "\n";
}