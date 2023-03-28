#include <iostream>
#include <map>
using namespace std;
map<string, pair<string,int>>m;
string find(string s){
    if(!m.count(s)){
        m[s]={s,1};
        return s;
    }
    else if(s==m[s].first){
        return s;
    }
    else {
        return s=find(m[s].first);
    }
}
void merge(string s, string c){
    s=find(s), c=find(c);
    if(s!=c){
        s>c ? m[s].first=c : m[c].first=s;
        m[s].second+=m[c].second;
        m[c].second=m[s].second;
    }
    cout << m[s].second << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t, n;
    string s, c;
    cin >> t;
    while(t--){
        cin >> n;
        m.clear();
        while(n--){
            cin >> s >> c;
            merge(s,c);
        }
    }
}