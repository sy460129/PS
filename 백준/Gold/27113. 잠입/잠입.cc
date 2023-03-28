#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int>>arr[100001];
bool ch;
int main(){
	int n, m, x, y=1, a, b; cin >> n >> m;
	char c, d;
	for(int i=1; i<n; i++){
		cin >> x;
		if(x==0) arr[i].push_back({0,0});
		else{
			if(x==1){
				cin >> a >> c;
				if(c=='R') arr[i].push_back({a, m});
				else arr[i].push_back({1,a});
			}
			else{
				cin >> a >> c >> b >> d;
				if(c=='R' && d=='L') arr[i].push_back({a,b});
				else if(c=='L' && d=='R'){
					arr[i].push_back({1,a});
					arr[i].push_back({b,m});
				}
				else if(c=='R' && d=='R') arr[i].push_back({a,m});
				else arr[i].push_back({1,b});
			}
		}
		ch=false;
		if(arr[i].size()!=2){
			if(y<arr[i][0].first || y>arr[i][0].second) ch=true;
			else if(y>=arr[i][0].first && y<=arr[i][0].second){
				if(arr[i][0].second!=m) y=arr[i][0].second+1, ch=true;
			}
			else if(y>arr[i][0].second) ch=true;
		}
		else{
			if(y<=arr[i][0].second){
				if(y<arr[i][1].first-1) y=arr[i][0].second+1, ch=true;
			}
			else if(y<arr[i][1].first) ch=true;
		}
		if(!ch){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}