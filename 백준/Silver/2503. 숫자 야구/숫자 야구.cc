#include <iostream>
using namespace std;
bool num[1000];
int main(){
	int n,s,b;
	string x, c;
	cin >> n;
	fill(num, num+1000, true);
	while(n--){
		cin >> x >> s >> b;
		for(int i=123; i<=999; i++){
			int st = 0, ba = 0;
			if(!num[i]){
				continue;
			}
			c=to_string(i);
			if(c[0]==c[1] || c[1]==c[2] || c[0]==c[2] || c[0]-'0'==0 || c[1]-'0'==0 || c[2]-'0'==0){
				num[i]=false;
				continue;
			}
			for(int j=0; j<3; j++){
				for(int k=0; k<3; k++){
					if(x[j]==c[k]){
						if(j==k){
							st++;
						}
						else{
							ba++;
						}
					}
				}
			}
			if(s!=st || b!=ba){
				num[i]=false;
			}
		}
	}
	int cnt=0;
	for(int i=123; i<=987; i++){
		if(num[i]){
			cnt++;
		}
	}
	cout << cnt;
}