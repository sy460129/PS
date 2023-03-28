#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int x=0, n, t; cin >> n;
    string s;
    while(n--){
        cin >> s;
        if(s!="all" && s[0]!='e'){
            cin >> t;
            if(s[0]=='a'){
                x|=(1<<t);
            }
            else if(s[0]=='r'){
                x&=~(1<<t);
            }
            else if(s[0]=='c'){
                x&(1<<t) ? cout << "1\n" : cout << "0\n";
            }
            else x^=(1<<t);
        }
        else{
            if(s[0]=='e') x=0;
            else x=(1<<21)-1;
        }
    }
}