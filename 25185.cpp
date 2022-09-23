#include <iostream>
#include <vector>
using namespace std;
int arr[10][3];
vector<string>v(4);
bool c;
int main(){
	int n, cnt;
	cin >> n;
	while(n--){
		cnt=0;
		for(int i=0; i<4; i++){
			cin >> v[i];
		}
		for(int i=0; i<4; i++){
			if(v[i][1]=='m'){
				arr[v[i][0]-'0'][0]++;
			}
			else if(v[i][1]=='p'){
				arr[v[i][0]-'0'][1]++;
			}
			else if(v[i][1]=='s'){
				arr[v[i][0]-'0'][2]++;
			}
		}
		for(int i=0; i<3; i++){
			for(int j=1; j<9; j++){
				if(arr[j][i]!=0){
					if(arr[j-1][i]!=0 && arr[j+1][i]!=0){
						c=true;
					}
				}
			}
			if(c){
				break;
			}
		}
		for(int i=0; i<3; i++){
			for(int j=0; j<10; j++){
				if(arr[j][i]>=3){
					c=true;
				}
			}
			if(c){
				break;
			}
		}
		for(int i=0; i<3; i++){
			for(int j=0; j<10; j++){
				if(arr[j][i]==2){
					cnt+=2;
				}
			}
		}
		if(cnt==4){
			c=true;
		}
		c ? cout << ":)\n" : cout << ":(\n";
		v.clear();
		c=false;
		fill(&arr[0][0], &arr[10][3], 0);
	}
}