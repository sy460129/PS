#include <iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=m; i++){
		if(i*n%m==1){
			cout << i;
			return 0;
		}
	}
}