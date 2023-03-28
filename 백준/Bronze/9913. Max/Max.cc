#include <iostream>
using namespace std;
int arr[10001];
int main() {
	int n, x, m=-1;
	cin >> n;
	while(n--){
		cin >> x;
		arr[x]++;
	}
	for(int i=0; i<10001; i++){
		m=max(m,arr[i]);
	}
	cout << m;
}