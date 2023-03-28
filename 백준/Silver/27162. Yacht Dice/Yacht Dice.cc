#include <iostream>
using namespace std;
int c[7];
int main(){
	int n, x, ans=0, res=0;
	string s;
	cin >> s;
	for(int i=0; i<3; i++){
		cin >> x;
		c[x]++;
		res+=x;
	}
	for(int i=1; i<=6; i++){
		c[i]++;
		res+=i;
		for(int j=1; j<=6; j++){
			int t=0, cnt=0;
			c[j]++;
			res+=j;
			for(int k=1; k<=6; k++){
				if(c[k]!=0) cnt++;
				if(s[k-1]=='Y') ans=max(ans, c[k]*k);
				if(c[k]>=4 && s[6]=='Y') ans=max(ans, 4*k);
				if(c[k]==5 && s[10]=='Y') ans=50;
			}
			if(cnt==2 && s[7]=='Y'){
				for(int k=1; k<=6; k++){
					if(c[k]==3 || c[k]==2) t+=c[k]*k;
				}
				ans=max(ans, t);
			}
			if((c[1] && c[2] && c[3] && c[4] && c[5]) && s[8]=='Y') ans=max(ans, 30);
			if((c[2] && c[3] && c[4] && c[5] && c[6]) && s[9]=='Y') ans=max(ans, 30);
			if(s[11]=='Y') ans=max(res, ans);
			res-=j;
			c[j]--;
		}
		res-=i;
		c[i]--;
	}
	cout << ans;
}