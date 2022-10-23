#include <iostream>
#include <algorithm>
using namespace std;
string sum(int n, string s){
    while(n--){
        string c;
        int x, y=0;
        for(int i=0; i<s.length(); i++){
            x=s[i]-'0';
            c+=to_string((x*2)%10+y);
            y=(x*2)/10;
        }
        if(y) c+='1';
        s=c;
    }
    return s;
}
void hannoi(int n, int from, int by, int to){
    if(n==1){
        cout << from << " " << to << "\n";
    }
    else{
        hannoi(n-1, from, to, by);
        cout << from << " " << to << "\n";
        hannoi(n-1, by, from, to);
    }
}
int main(){
    int k; cin >> k;
    string t="1";
    string c=sum(k, t);
    reverse(c.begin(), c.end());
    char d=c[c.length()-1];
    int l=d-'0'; l--;
    c[c.length()-1]=l+'0';
    cout << c << "\n";
    if(k<=20){
       hannoi(k, 1, 2, 3);
    }
}