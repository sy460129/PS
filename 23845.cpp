#include <iostream>
#include <queue>
using namespace std;
queue<long long>q;
long long arr[200002];
int main(){
	long long n,x,cnt=0, res=0;
	cin >> n;
	while(n--){
		cin >> x;
		arr[x]++;
	}
	for(int i=1; i<=200001; i++){
		if(arr[i]!=0){
			if(arr[i]!=1 && q.empty()) q.push(i);
			cnt++;
			arr[i]--;
		}
		else if(arr[i]==0 && cnt!=0){
			res+=cnt*(i-1);
			cnt=0;
			if(!q.empty()){
				i=q.front()-1;
				q.pop();
			}
		}
	}
	cout << res;
}