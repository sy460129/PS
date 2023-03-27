#include <iostream>
#include <iomanip>
using namespace std;
int x[36];
int y[36];
int main(){
	int n, ans=0;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x[i] >> y[i];
	}
	for(int i=0; i<n-2; i++){
		for(int j=i+1; j<n-1; j++){
			for(int k=j+1; k<n; k++){
				ans=max(ans, abs(x[i]*y[j] + x[j]*y[k] + x[k]*y[i] - x[j]*y[i] - x[k]*y[j] - x[i]*y[k]));
			}
		}
	}
	cout << fixed << setprecision(9) << (double)ans/2;
}