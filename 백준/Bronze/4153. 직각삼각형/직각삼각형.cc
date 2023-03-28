#include <iostream>
#include <algorithm>
using namespace std;
int dp[46];
int main(){
	int x, y, z;
	 while(1){
	 	bool c=false;
	 	int arr[3];
	 	for(int i=0; i<3; i++){
	 		cin >> arr[i];
	 		if(arr[i]!=0){
	 			arr[i]*=arr[i];
	 			c=true;
	 		}
	 	}
	 	if(!c){
	 		break;
	 	}
	 	sort(arr, arr+3);
	 	if(arr[2]==arr[0]+arr[1]){
	 		cout << "right\n";
	 	}
	 	else{
	 		cout << "wrong\n";
	 	}
	 }
}