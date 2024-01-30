#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int pa[2000001], pb[2000001];
vector<int>va, vb;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, a, b, sum=0, cnt=0; cin >> n >> a >> b;
	for(int i=0; i<a; i++) cin >> pa[i];
	for(int i=0; i<a; i++){
		for(int j=i; j<a+i; j++){
			sum+=pa[j%a];
			if((i && j%a==i-1) || sum>n) break;
			va.push_back(sum);
		}
		sum=0;
	}
	for(int i=0; i<b; i++) cin >> pb[i];
	for(int i=0; i<b; i++){
		for(int j=i; j<b+i; j++){
			sum+=pb[j%b];
			if((i && j%b==i-1) || sum>n) break;
			vb.push_back(sum);
		}
		sum=0;
	}
	va.push_back(0), vb.push_back(0);
	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());
	for(int i=0; i<va.size(); i++){
		auto it=lower_bound(vb.begin(), vb.end(), n-va[i])-vb.begin();
		auto it2=upper_bound(vb.begin(), vb.end(), n-va[i])-vb.begin();
		cnt+=it2-it;
	}
	cout << cnt;
}