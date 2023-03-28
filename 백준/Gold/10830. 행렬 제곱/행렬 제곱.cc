#include <iostream>
using namespace std;
typedef unsigned long long ull;
ull arr[6][6];
ull ans[6][6];
ull mid[6][6];
ull n, m;
void mul(ull ans[6][6], ull arr[6][6]){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				mid[i][j]+=(ans[i][k]*arr[k][j]);
			}
			mid[i][j]%=1000;
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			ans[i][j]=mid[i][j];
			mid[i][j]=0;
		}
	}
}
int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
            ans[i][j]=arr[i][j]%1000;
		}
	}
    m--;
	while(m!=0){
		if(m%2==1){
			mul(ans, arr);
		}
		mul(arr, arr);
		m/=2;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}