#include<iostream>
#include<cmath>
using namespace std;
using ll=long long;
pair<ll,ll>p;
int main(int argc, char** argv)
{
	int test_case, T;
    ll a;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> a;
        p={1e12,1e12};
        for(ll i=1; i<=sqrt(a); i++){
            if(a%i==0 && a%(a/i)==0){
                if(p.first+p.second>i+a/i) p={i,a/i};
            }
        }
		cout << "#" << test_case << " " << p.first+p.second-2 << "\n";
	}
	return 0;
}