#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define MAX 9876543211
using namespace std;
using ll = long long;
vector<ll>v;
bool c;
int main() {
    int n; cin >> n;
    if(n<=10){
        cout << n;
        return 0;
    }
    n-=10;
    ll t = 20;
    while(n!=0){
        string s=to_string(t);
        c=true;
        for(int i=1; i<s.length(); i++) {
            if(s[i-1]-'0'<=s[i]-'0') {
                t+=pow(10, s.length()-i);
                t-=((s[i]-'0')* pow(10, s.length()-i-1));
                c=false;
                break;
            }
        }
        if(c) n--, t++;
        if(t>MAX){
            cout << -1;
            return 0;
        }
    }
    cout << --t;
}