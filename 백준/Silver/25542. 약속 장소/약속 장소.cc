#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n, m, t=0, cnt;
	cin >> n >> m;
	vector<string>v(n);
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	for(int i=1; i<n; i++){
		cnt=0;
		for(int j=0; j<m; j++){
			if(v[0][j]!=v[i][j]){
				cnt++;
			}
		}
		if(cnt>2){
			cout << "CALL FRIEND";
			return 0;
		}
		if(cnt==2){
			t=i;
			break;
		}
	}
	if(t==0){
		cout << v[0];
		return 0;
	}
	vector<string> vec;
	for(int i=0; i<m; i++){
		if(v[0][i]!=v[t][i]){
			string tmp=v[0];
			for(int j=0; j<26; j++){
				tmp[i]=char(j+'A');
				vec.push_back(tmp);
			}
		}
	}
	for(int i=0; i<vec.size(); i++){
		bool c=true;
		for(int j=1; j<n; j++){
			cnt=0;
			for(int k=0; k<m; k++){
				if(vec[i][k]!=v[j][k]){
					cnt++;
				}
			}
			if(cnt>1){
				c=false;
			}
		}
		if(c){
			cout << vec[i];
			return 0;
		}
	}
	cout << "CALL FRIEND";
}