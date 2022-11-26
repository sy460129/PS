#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, k, p=0;
    string s;
    vector<char>v;
    cin >> n >> k >> s;
    v.push_back(s[0]);
    for(int i=1; i<s.length(); i++){
        while(!v.empty() && v.back()<s[i] && p<k) v.pop_back(), p++;
        v.push_back(s[i]);
    }
    while(p!=k){
        v.pop_back(), p++;
    }
    for(auto e : v) cout << e;
}