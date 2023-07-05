#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int n; cin >> n;
	double d=1;
	for(int i=2; i<=n; i++){
		d+=1/(1-((i-1)/(double)n));
	}
	cout << fixed << setprecision(8) << d;
}