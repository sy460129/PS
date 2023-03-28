#include <iostream>
#include <vector>
using namespace std;
int dp[1001];
char arr[1001];
vector<int> b, o, j;
int main() {
	fill(dp, dp+1001, -1);
	int n; cin >> n;
	dp[0]=0;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		if(arr[i]=='B') b.push_back(i);
		else if(arr[i]=='O') o.push_back(i);
		else j.push_back(i);
	}
	for(int i=1; i<n; i++) {
		if(arr[i]=='O'){
			for(int k=0; k<b.size(); k++){
				if(b[k]>i) break;
				if(dp[b[k]]!=-1){
					dp[i]==-1 ? dp[i]=(i-b[k])*(i-b[k])+dp[b[k]] : dp[i]=min(dp[i],(i-b[k])*(i-b[k])+dp[b[k]]);
				}
			}
		}
		else if(arr[i]=='J'){
			for(int k=0; k<o.size(); k++){
				if(o[k]>i) break;
				if(dp[o[k]]!=-1){
					dp[i]==-1 ? dp[i]=(i-o[k])*(i-o[k])+dp[o[k]] : dp[i]=min(dp[i],(i-o[k])*(i-o[k])+dp[o[k]]);
				}
			}
		}
		else {
			for(int k=0; k<j.size(); k++){
				if(j[k]>i) break;
				if(dp[j[k]]!=-1){
					dp[i]==-1 ? dp[i]=(i-j[k])*(i-j[k])+dp[j[k]] : dp[i]=min(dp[i],(i-j[k])*(i-j[k])+dp[j[k]]);
				}
			}
		}
	}
	cout << dp[n-1];
}