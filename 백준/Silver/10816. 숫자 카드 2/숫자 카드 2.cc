#include <iostream>
using namespace std;
int arr[10000001][2];
int n, x;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	while(n--){
		cin >> x;
		if(x>=0){
			arr[x][0]++;
		}
		else{
			x*=-1;
			arr[x][1]++;
		}
	}
	cin >> n;
	while(n--){
		cin >> x;
		if(x>=0){
			cout << arr[x][0] << " ";
		}
		else{
			x*=-1;
			cout << arr[x][1] << " ";
		}
	}
}