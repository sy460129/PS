#include <iostream>
#include <queue>
#define rep(a,b) for(int i=a; i<b; i++)
using namespace std;
int al[26], dp[26];
queue<int>q;
bool one, two;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s, c; cin >> s;
	int n, cnt, o=0; cin >> n;
	rep(0,s.length()) al[s[i]-'a']++;
	while(n--){
		one=two=false;
		cnt=0;
		cin >> c;
		if(c.length()<s.length()) cout << "NO\n";
		else if(c.length()==s.length()){
			rep(0, c.length()){
				if(al[c[i]-'a'] && al[c[i]-'a']>dp[c[i]-'a']) dp[c[i]-'a']++;
				else one ? two=true : one=true;
			}
			if(!one || two) cout << "NO\n";
			else cout << "YES\n";
		}
		else{
			rep(0, c.length()){
				q.push(c[i]-'a');
				if(q.size()<=s.length()){
					if(al[c[i]-'a']){
						dp[c[i]-'a']++;
						if(al[c[i]-'a']>=dp[c[i]-'a']) cnt++;
					}
					if(q.size()==s.length()){
						if(cnt>=s.length()-1){
							two=true;
							break;
						}
					}
				}
				else{
					if(al[q.front()]){
						cnt-=min(al[q.front()],dp[q.front()]);
						dp[q.front()]--;
						cnt+=min(al[q.front()],dp[q.front()]);
					}
					if(al[c[i]-'a']){
						cnt-=min(al[c[i]-'a'],dp[c[i]-'a']);
						dp[c[i]-'a']++;
						cnt+=min(al[c[i]-'a'],dp[c[i]-'a']);
					}
					q.pop();
					if(cnt>=s.length()-1){
						two=true;
						break;
					}
				}
			}
			if(cnt>=s.length()-1) two=true;
			two ? cout << "YES\n" : cout << "NO\n";
			while(!q.empty()) q.pop();
		}
		rep(0,26) dp[i]=0;
	}
}