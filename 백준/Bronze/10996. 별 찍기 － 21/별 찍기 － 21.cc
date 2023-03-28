#include <iostream>
using namespace std;
char arr[202][202];
int main(){
	int n;
	cin >> n;
	for(int i=0; i<n*2; i++){
		for(int j=0; j<n; j++){
			if(i%2==0){
				if(j%2==0){
					arr[i][j]='*';
				}
				else{
					arr[i][j]=' ';
				}
			}
			else{
				if(j%2!=0){
					arr[i][j]='*';
				}
				else{
					arr[i][j]=' ';
				}
			}
		}
	}
	for(int i=0; i<n*2; i++){
		for(int j=0; j<n; j++){
			cout << arr[i][j];
		}
		cout << "\n";
	}
}