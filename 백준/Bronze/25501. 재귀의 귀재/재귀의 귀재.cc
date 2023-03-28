#include <iostream>
using namespace std;
int main(){
    int n; cin >> n;
    string s;
    while(n--){
        bool c=true;
        int cnt=1;
        cin >> s;
        for(int i=0; i<s.length()/2; i++){
            if(s[i]!=s[s.length()-1-i]){
                c=false;
                break;
            }
            cnt++;
        }
        c ? cout << 1 << " " << cnt << "\n" : cout << 0 << " " << cnt << "\n";
    }
}