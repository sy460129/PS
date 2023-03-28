#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string p(string s, string c){
    string ans;
    int y=0;
    for(int i=0; i<s.length(); i++){
        ans+=to_string((((s[i]-'0')+(c[i]-'0'))+y)%10);
        y=(((s[i]-'0')+(c[i]-'0'))+y)/10;
    }
    if(y==1) ans+="1";
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
    string s, c, a; cin >> s >> c;
    reverse(s.begin(), s.end());
    reverse(c.begin(), c.end());
    if(s.length()>c.length()){
        while(s.length()!=c.length()) c+="0";
    }
    else{
        while(s.length()!=c.length()) s+="0";
    }
    cout << p(s, c);
}