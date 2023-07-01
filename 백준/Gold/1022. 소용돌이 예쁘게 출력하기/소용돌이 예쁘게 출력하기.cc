#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int arr[51][51];
int main(){
	int i=5000, j=5000, x=1, t=0, ans=2, r1, r2, c1, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	while(1){
		int cnt=0;
		while(1){
			x>0 ? j++ : j--;			
			if(j>=c1+5000 && j<=c2+5000 && i>=r1+5000 && i<=r2+5000) arr[i-5000-r1][j-5000-c1]=ans;
			cnt++, ans++;
			if(i>=10000 && j>=10000) break;
			if(cnt==abs(x)) break;
		}
		if(i>=10000 && j>=10000) break;
		cnt=0;
		while(1){
			x>0 ? i-- : i++;
			if(i>=r1+5000 && i<=r2+5000 && j>=c1+5000 && j<=c2+5000) arr[i-5000-r1][j-5000-c1]=ans;
			cnt++, ans++;
			if(cnt==abs(x)) break;
		}
		t++;
		x<0 ? x-- : x++;
		if(t%2) x*=-1;
		else t=0, x*=-1;
		if(i>=10000 && j>=10000) break;
	}	
	t=1;
	for(int i=0; i<=r2-r1; i++){
		for(int j=0; j<=c2-c1; j++){
			t=max(t, (int)(to_string(arr[i][j]).length()));
		}
	}
	for(int i=0; i<=r2-r1; i++){
		for(int j=0; j<=c2-c1; j++){
			for(int k=0; k<t-(int)(to_string(arr[i][j]).length()); k++) cout << " ";
			!arr[i][j] ? cout << 1 << " " : cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}