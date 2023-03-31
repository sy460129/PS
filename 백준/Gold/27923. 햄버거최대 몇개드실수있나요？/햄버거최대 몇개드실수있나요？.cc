#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
int arr[200001], cola[200001], check[2000001];
long long ans;
queue<int>q;
bool cmp(int a, int b){
	return a>b;
}
int main(){
	int n, m, k, x, sum=0; cin >> n >> m >> k;
	for(int i=0; i<n; i++) cin >> arr[i];
	sort(arr, arr+n, cmp);
	for(int i=0; i<m; i++){
		cin >> x;
		cola[x-1]++;
	}
	for(int i=0; i<n; i++){
		check[i]=min(30,sum+cola[i]);
		sum+=cola[i];
		q.push(cola[i]);
		if(q.size()==k){
			sum-=q.front();
			q.pop();
		}
	}
	sort(check, check+n, cmp);
	for(int i=0; i<n; i++) ans+=arr[i]/pow(2,check[i]);
	cout << ans;
}