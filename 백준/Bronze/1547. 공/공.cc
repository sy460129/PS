#include <iostream>
using namespace std;
int ball[4];
int main(){
	int n, x, y;
	cin >> n;
	ball[1] = 1;
	while(n--){
		cin >> x >> y;
		swap(ball[x], ball[y]);
	}
	for(int i = 1; i <= 3; i++){
		if(ball[i]){
			cout << i;
		}
	}
}