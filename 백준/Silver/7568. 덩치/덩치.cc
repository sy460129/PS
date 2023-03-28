#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int>>v;
int main(){
	int n, t=1, a, b;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a >> b;
		v.push_back({a,b});
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(v[i].first < v[j].first && v[i].second < v[j].second){
				t++;
			}
		}
		cout << t << " ";
		t=1;
	}
}