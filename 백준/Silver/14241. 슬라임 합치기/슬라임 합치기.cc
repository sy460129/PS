#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>v, vec;
int main(){
	int n, x, ans=0;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for(int i=0; i<n; i++){
		if(vec.empty()){
			vec.push_back(v[i]);
		}
		else{
			ans+=vec.back()*v[i];
			vec.push_back(vec.back()+v[i]);
		}
	}
	cout << ans;
}