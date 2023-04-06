#include <iostream>
#include <queue>
using namespace std;
int arr[26];
int main(){
	queue<char>q;
	int n, cnt=0, ans=0; cin >> n;
	string s; cin >> s;
	for(int i=0; i<s.length(); i++){
		q.push(s[i]);
		arr[s[i]-'a']++;
		if(arr[s[i]-'a']==1){
			cnt++;
			if(cnt>n){
				while(1){
					int t=q.front()-'a';
					q.pop();
					arr[t]--;
					if(!arr[t]){
						cnt--;
						break;
					}
				}
			}
		}
		ans=max(ans, (int)q.size());
	}
	cout << ans;
}