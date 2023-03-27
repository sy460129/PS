#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int n;
    long long res = 2147483647;
    cin >> n;
    long long* arr = new long long[n];
    vector<pair<long long, long long>>v;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
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
                v.clear();
                if (arr[c] < arr[mid]) {
                    v.push_back({ arr[c], arr[mid] });
                }
                else {
                    v.push_back({ arr[mid], arr[c] });
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
    cout << v.front().first << " " << v.front().second;
}