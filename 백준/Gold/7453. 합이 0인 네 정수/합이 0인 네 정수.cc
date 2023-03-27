#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[4001], b[4001], c[4001], d[4001];
vector<int>ab, cd;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	long long cnt=0;
	for(int i=0; i<n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			ab.push_back(a[i]+b[j]);
			cd.push_back(c[i]+d[j]);
		}
	}
	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());
	for(int i=0; i<ab.size(); i++){
		int t=1;
		for(int j=i+1; j<ab.size(); j++) {
			if(ab[j]!=ab[i]) break;
			else t++, i++;
		}
		auto it=lower_bound(cd.begin(), cd.end(), -ab[i]);
		auto it2=upper_bound(cd.begin(), cd.end(), -ab[i]);
		cnt+=(it2-it)*t;
	}
	cout << cnt;
}