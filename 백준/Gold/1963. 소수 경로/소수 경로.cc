#include <iostream>
#include <queue>
using namespace std;
int arr[10001];
bool dp[10001];
bool c;
queue<pair<string,int>>q;
int main(){
	for(int i=2; i<=10000; i++){
		if(arr[i]==0){
			for(int j=2; j<=10000/i; j++){
				arr[i*j]=1;
			}
		}
	}
	int n, ans, y;
	string s, t, h;
	cin >> n;
	while(n--){
		c=false;
		ans=0;
		cin >> s >> t;
		q.push({s,0});
		if(s==t){
			cout << 0 << "\n";
			q.pop();
			continue;
		}
		dp[stoi(s)]=true;
		while(!q.empty()){
			s=q.front().first, y=q.front().second;
			q.pop();
			h=s;
			for(int i=0; i<4; i++){
				s=h;
				for(int j=0; j<=9; j++){
					if(i==0 && j==0){
						continue;
					}
					s[i]=j+'0';
					if(arr[stoi(s)]==0 && !dp[stoi(s)]){
						if(s==t){
							ans=y;
							c=true;
							break;
						}
						q.push({s,y+1});
						dp[stoi(s)]=true;
					}
				}
				if(c) break;
			}
			if(c) break;
		}
		!c ? cout << "Impossible\n" : cout << ans+1 << "\n";
		while(!q.empty()) q.pop();
		fill(dp, dp+10001, false);
	}
}