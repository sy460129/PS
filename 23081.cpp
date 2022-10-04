#include <iostream>
#include <vector>
using namespace std;
char arr[501][501];
vector<pair<int,int>>v;
int n, cnt = 0, h=-1;
void bfs(int x, int y){
	int t=x, p=y, k=0;
	for(int i=x + 1; i<n; i++){
		if(arr[i][y]=='W'){
			k++;
		}
		else{
			if(arr[i][y]=='B'){
				cnt+=k;
			}
			break;
		}
	}
	k=0;
	for(int i=x - 1; i>=0; i--){
		if(arr[i][y]=='W'){
			k++;
		}
		else {
			if(arr[i][y]=='B'){
				cnt+=k;
			}
			break;
		}
	}
	k=0;	
	for(int i=t + 1; i<n; i++){
		p++;
		if(p>=n){
			break;
		}
		else if(arr[i][p]=='W'){
			k++;
		}
		else{
			if(arr[i][p]=='B'){
				cnt+=k;
			}
			break;
		}
	}
	k=0;
	p=y;
	for(int i=t - 1; i>=0; i--){
		p--;
		if(p<0){
			break;
		}
		if(arr[i][p]=='W'){
			k++;
		}
		else {
			if(arr[i][p]=='B'){
				cnt+=k;
			}
			break;
		}
	}
	k=0;
	p=y;
	for(int i=p + 1; i<n; i++){
		t--;
		if(t<0){
			break;
		}
		if(arr[t][i]=='W'){
			k++;
		}
		else{
			if(arr[t][i]=='B'){
				cnt+=k;
			}
			break;
		}
	}
	k=0;
	t=x;
	for(int i=p - 1; i>=0; i--){
		t++;
		if(t>=n){
			break;
		}
		if(arr[t][i]=='W'){
			k++;
		}
		else{
			if(arr[t][i]=='B'){
				cnt+=k;
			}
			break;
		}
	}
	k=0;
	for(int i=y-1; i>=0; i--){
		if(arr[x][i]=='W'){
			k++;
		}
		else{
			if(arr[x][i]=='B'){
				cnt+=k;
			}
			break;
		}
	}
	k=0;
	for(int i=y+1; i<n; i++){
		if(arr[x][i]=='W'){
			k++;
		}
		else{
			if(arr[x][i]=='B'){
				cnt+=k;
			}
			break;
		}
	}
	k=0;
	if(cnt>h && cnt >=1){
		if(!v.empty()){
			v.clear();
		}
		v.push_back({x,y});
		h=cnt;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[j][i];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cnt = 0;
			if(arr[j][i]=='.'){
				bfs(j,i);
			}
		}
	}
	if(v.empty()){
		cout << "PASS";
		return 0;
	}
	cout << v[0].first << " " << v[0].second << "\n" << h;
}