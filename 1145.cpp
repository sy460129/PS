#include <iostream>
using namespace std;
int main() {
	int cnt;
	int arr[5];
	for(int i=0; i<5; i++){
		cin >> arr[i];
	}
	for(int i=1; i<=100000000; i++){
		cnt=0;
		for(int j=0; j<5; j++){
			if(i%arr[j]==0){
				cnt++;
			}
		}
		if(cnt>=3){
			cout << i;
			return 0;
		}
	}
}