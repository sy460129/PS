#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n, t; cin >> n;
    while(n--){
        queue<char>q;
        string s; cin >> t >> s;
        for(int i=0; i<s.length(); i++){
            if(i!=t-1) q.push(s[i]);
        }
        while(!q.empty()){
            cout << q.front();
            q.pop();
        }
        cout << "\n";
    }
}