#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool check[2001];
int main(){
	int n, x, cnt=0;
	cin >> n;
	vector<int>v(n);
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	if(v.size()<=2){
		cout << 0;
		return 0;
	}
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			x=v[i]+v[j];
			auto it=lower_bound(v.begin(), v.end(), x)-v.begin();
			if(check[it]){
				continue;
			}
			while(v[it]==x && it<v.size()){
				if(it==i || it==j){
					it++;
					continue;
				}
				check[it]=true;
				it++;
				cnt++;
			}
			it--;
			if(x==v[i] && it!=0 && v[it-1]==x && cnt!=0){
				check[i]=true;
				cnt++;
			}
			if(x==v[j] && it!=0 && v[it-1]==x && cnt!=0){
				check[j]=true;
				cnt++;
			}
		}
	}
	cout << cnt;
}