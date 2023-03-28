#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<string ,int>m;
vector<int>check[600001];
int main(){
    int n, x, t=0; cin >> n;
    string s;
    while(n--){
        cin >> s >> x;
        m[s]+=x;
    }
    for(auto i=m.begin(); i!=m.end(); i++){
        check[(int)((i->second)*1.618)].push_back(t);
        t++;
    }
    t=0;
    for(auto i=m.begin(); i!=m.end(); i++){
        if(!check[i->second].empty() && !(check[i->second].size()==1 && check[i->second].back()==t)){
            cout << "Delicious!";
            return 0;
        }
        t++;
    }
    cout << "Not Delicious...";
}