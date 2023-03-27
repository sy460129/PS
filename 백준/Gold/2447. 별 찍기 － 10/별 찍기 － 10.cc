#include <iostream>
using namespace std;
void star(int i, int j){
	if(i%3==1 && j%3==1) cout << " ";
	else if(i>=3 && j>=3){
		star(i/3, j/3);
		return;
	}
	else cout << "*";
}
int main(){
	int n; cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			star(i,j);

		}
		cout << "\n";
	}
}