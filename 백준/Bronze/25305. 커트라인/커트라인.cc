#include <iostream>
#include <set>
using namespace std;
multiset<int>s;
int main(){
    int n, k, x; cin >> n >> k;
    while(n--){
        cin >> x;
        s.insert(x);
    }
    k--;
    while(k--) s.erase(--s.end());
    cout << *(--s.end());
}