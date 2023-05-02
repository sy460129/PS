#include <iostream>
using namespace std;
int main(){
	int n, m; cin >> n >> m;
	int ans=-1, cnt=0;
	for(int i=1; i<100; i++){
		cnt+=i;
		if(i<m-1) continue;
		if(n-cnt<0) break;
		if((n-cnt)%(i+1)==0){
			ans=(n-cnt)/(i+1);
			break;
		}
	}
	if(ans==-1) cout << -1;
	else{
		int t=1;
		while(cnt>=0){
			cout << ans+t-1 << " ";
			cnt-=t;
			t++;
		}
	}
}