#include <iostream>
#include <queue>
using namespace std;
int arr[100001];
queue<int>q;
int main(){
	int n, m, t=0, cnt=0; cin >> n >> m;
	for(int i=0; i<n; i++) cin >> arr[i];
	for(int i=0; i<n-m; i++){
		if(!q.empty() && q.front()==i) q.pop(), t--;
		arr[i]+=t;
		if(arr[i]%2){
			q.push(i+m);
			t++, cnt++;
			arr[i]--;
		}
	}
	for(int i=n-m; i<n; i++){
		if(!q.empty() && q.front()==i) q.pop(), t--;
		arr[i]+=t;
		if(i==n-m && arr[i]%2){
			arr[i]--;
			t--, cnt++;
		}
	}
	for(int i=0; i<n; i++){
		if(arr[i]%2){
			cout << "Insomnia";
			return 0;
		}
	}
	cout << cnt;
}