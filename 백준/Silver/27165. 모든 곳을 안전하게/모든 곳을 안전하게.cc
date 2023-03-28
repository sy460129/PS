#include <iostream>
#include <vector>
using namespace std;
int arr[1000001];
vector<int>v;
bool c;
int main(){
	int n, m; cin >> n;
	for(int i=0; i<=n; i++) {
		cin >> arr[i];
		if(arr[i]==1) c=true, v.push_back(i);
	}
	cin >> m;
	if(v.size()>2){
		cout << "NO";
		return 0;
	}
	else if(!c){
		for(int i=0; i<=n-m; i++) {
			if(arr[i]>2 && arr[i+m]){
				cout << "YES\n" << i << " " << i+m;
				return 0;
			}
		}
	}
	else{
		if(v.size()==1){
			if((v[0]>=m && arr[v[0]-m]>2)){
				cout << "YES\n" << v[0]-m << " " << v[0];
				return 0;
			}
			else if(v[0]<=n-m && arr[v[0]+m]){
				cout << "YES\n" << v[0] << " " << v[0]+m;
				return 0;
			}
		}
		else{
			if(v[0]+m==v[1]){
				cout << "YES\n" << v[0] << " " << v[1];
				return 0;
			}
		}
	}
	cout << "NO";
}