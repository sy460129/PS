#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string arr[51];
int n, k, ans, t;
bool check[26];
vector<char>v;
void track(int u, int cnt){
    if(cnt==k || u==v.size()){
        int res=0;
        for(int i=0; i<n; i++){
            bool c=true;
            for(int j=0; j<arr[i].length(); j++){
                int p=(arr[i][j]-'a');
                if((1<<p)&t) c=true;
                else{
                    c=false;
                    break;
                }
            }
            if(c) res++;
        }
        ans=max(ans, res);
        return;
    }
    for(int i=u; i<v.size(); i++){
        if(!check[v[i]-'a']){
            int l=v[i]-'a';
            check[v[i]-'a']=true;
            t|=(1<<l);
            track(i+1, cnt+1);
            check[v[i]-'a']=false;
            t&=~(1<<l);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        for(int j=0; j<arr[i].size(); j++) {
            if(arr[i][j]!='a' && arr[i][j]!='n' && arr[i][j]!='t' && arr[i][j]!='i' && arr[i][j]!='c') v.push_back(arr[i][j]);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    if(k<5){
        cout << 0;
        return 0;
    }
    t|=(1<<('a'-'a'));
    t|=(1<<('n'-'a'));
    t|=(1<<('t'-'a'));
    t|=(1<<('i'-'a'));
    t|=(1<<('c'-'a'));
    check[0]=true;
    check['n'-'a']=true;
    check['t'-'a']=true;
    check['i'-'a']=true;
    check['c'-'a']=true;
    track(0, 5);
    cout << ans;
}