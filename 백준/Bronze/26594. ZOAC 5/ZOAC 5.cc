#include <iostream>
using namespace std;
int main(){
    string s; cin >> s;
    int cnt=1;
    for(int i=1; i<s.length(); i++){
        if(s[i]!=s[i-1]) break;
        cnt++;
    }
    cout << cnt;
}