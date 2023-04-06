#include <iostream>
#include <queue>
using namespace std;
queue<char>q;
int arr[26];
int main() {
	string s;
	int n, b, w, bb=0, ww=0, ans=0, j=0;
	cin >> n >> b >> w >> s;
	for(int i=0; i<n; i++){
		q.push(s[i]);
		arr[s[i]-'A']++;
		if(arr[1]>b){
			if(arr[22]>=w){
				ans=max(ans, (int)q.size()-1);
			}
			while(!q.empty()){
				if(q.front()=='B'){
					arr[1]--;
					q.pop();
					break;
				}
				arr[22]--;
				q.pop();
			}
		}
	}
	if(arr[22]>=w){
		ans=max(ans, (int)q.size());
	}
	cout << ans;
}