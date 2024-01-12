#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
int arr[101][101];
int dx[]={-1,1,0,0};
int dy[]={-0,0,1,-1};
vector<tuple<int,int,int>>v[101][101], vec[101][101];
bool flag;
int main(){
	int n, m, t, r, c, s, d, z, x, y, nx, ny, ans=0; cin >> n >> m >> t;
	while(t--){
		cin >> r >> c >> s >> d >> z;
		d--;
		v[r][c].push_back({s,d,z});
	}
	for(int i=1; i<=m; i++){
		flag=false;
		for(int j=1; j<=n; j++){
			if(!v[j][i].empty()) {
				ans+=get<2>(v[j][i][0]);
				flag=true;
				v[j][i].clear();
			}
			if(flag) break;
		}
		for(int p=1; p<=n; p++){
			for(int q=1; q<=m; q++){
				if(!v[p][q].empty()){
					auto cur=v[p][q][0];
					v[p][q].pop_back();
					s=get<0>(cur), d=get<1>(cur), z=get<2>(cur);
					if(d==0){
						flag=false;
						x=s/(n-1), y=s%(n-1);
						if(x%2==0) y=n-y;
						else flag=true, d=1, y++;
						nx=n-p;
						while(nx--){
							flag ? y++ : y--;
							if(y>n) y=n-1, d=0, flag=false;
							else if(y<1) y=2, d=1, flag=true;
						}
						if(!vec[y][q].empty()){
							if(get<2>(vec[y][q][0])<z){
								vec[y][q].pop_back();
								vec[y][q].push_back({s,d,z});
							}
						}
						else vec[y][q].push_back({s,d,z});
					}
					else if(d==1){
						flag=true;
						x=s/(n-1), y=s%(n-1);
						if(x%2==0) y++;
						else flag=false, d=0, y=n-y;
						nx=p-1;
						while(nx--){
							flag ? y++ : y--;
							if(y>n) y=n-1, d=0, flag=false;
							else if(y<1) y=2, d=1, flag=true;
						}
						if(!vec[y][q].empty()){
							if(get<2>(vec[y][q][0])<z){
								vec[y][q].pop_back();
								vec[y][q].push_back({s,d,z});
							}
						}
						else vec[y][q].push_back({s,d,z});
					}
					else if(d==2){
						flag=true;
						x=s/(m-1), y=s%(m-1);
						if(x%2==0) y++;
						else flag=false, d=3, y=m-y;
						nx=q-1;
						while(nx--){
							flag ? y++ : y--;
							if(y>m) y=m-1, d=3, flag=false;
							else if(y<1) y=2, d=2, flag=true;
						}
						if(!vec[p][y].empty()){
							if(get<2>(vec[p][y][0])<z){
								vec[p][y].pop_back();
								vec[p][y].push_back({s,d,z});
							}
						}
						else vec[p][y].push_back({s,d,z});
					}
					else{
						flag=false;
						x=s/(m-1), y=s%(m-1);
						if(x%2==0) y=m-y;
						else flag=true, d=2, y++;
						nx=m-q;
						while(nx--){
							flag ? y++ : y--;
							if(y>m) y=m-1, d=3, flag=false;
							else if(y<1) y=2, d=2, flag=true;
						}
						if(!vec[p][y].empty()){
							if(get<2>(vec[p][y][0])<z){
								vec[p][y].pop_back();
								vec[p][y].push_back({s,d,z});
							}
						}
						else vec[p][y].push_back({s,d,z});
					}
				}
			}
		}
		for(int p=1; p<=n; p++){
			for(int q=1; q<=m; q++){
				v[p][q]=vec[p][q];
				vec[p][q].clear();
			}
		}
	}
	cout << ans;
}