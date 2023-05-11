#include <iostream>
#include <queue>
using namespace std;
int arr[101];
int num[101];
bool check[101];
queue<int>q[101];
int main(){
	int n, m, cnt=0, ans=0; cin >> n >> m;
	for(int i=0; i<m; i++){
		cin >> arr[i];
		num[arr[i]]++;
		q[arr[i]].push(i);
	}
	for(int i=0; i<m; i++){
		if(cnt<n && !check[arr[i]]) cnt++;
		else if(!check[arr[i]]){
			int res=0, t;
			for(int j=1; j<=m; j++){
				if(check[j]){
					if(q[j].empty()){
						t=j;
						break;
					}
					else if(q[j].front()>res){
						res=q[j].front();
						t=j;
					}
				}
			}      
			ans++;
			check[t]=false;
		}
		check[arr[i]]=true;
		num[arr[i]]--;
		q[arr[i]].pop();
	}
	cout << ans;
}