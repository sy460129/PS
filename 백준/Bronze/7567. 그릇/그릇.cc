#include <iostream>
using namespace std;
int main() {
    string s; cin >> s;
    int cnt;
    for(int i=0; i<s.length(); i++){
        if(i==0) cnt=10;
        else{
            s[i-1]==s[i] ? cnt+=5 : cnt+=10;
        }
    }
    cout << cnt;
}