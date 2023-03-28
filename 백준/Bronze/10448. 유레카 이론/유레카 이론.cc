#include <iostream>
using namespace std;
int a[51];
int b[51];
int c[51];
int main(){
	for(int i = 1; i <= 50; i++){
		a[i] = a[i - 1] + i;
		b[i] = a[i], c[i] = a[i];
	}
	int n, x;
	cin >> n;
	while(n--){
		bool ch = false;
		cin >> x;
		for(int i = 1; i <= 50; i++){
			for(int j = 1; j <= 50; j++){
				for(int k = 1; k <= 50; k++){
					if(a[i] + b[j] + c[k] > x){
						break;
					}
					if(a[i] + b[j] + c[k] == x){
						ch = true;
					}
				}
				if(ch){
					break;
				}
			}
			if(ch){
				break;
			}
		}
		if(ch){
			cout << 1 << "\n";
		}
		else{
			cout << 0 << "\n";
		}
	}
}