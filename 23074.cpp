#include <iostream>
#define rep_(i, a, b) for(int i=a; i<=b; i++)
#define MAX 500000
using namespace std;
bool check[MAX+1];
int main(){
	rep_(i, 2, MAX){
		if(!check[i]){
			rep_(j, 2, MAX/i){
				check[i*j]=true;
			}
		}
	}
	int n; cin >> n;
	cout << max(1,n/2) << "\n";
	rep_(i, 1, n){
		if(i<=3) cout << 1 << " ";
		else{
			!check[i] ? cout << 1 << " " : cout << i/2 << " ";
		}
	}
}