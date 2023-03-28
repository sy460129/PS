#include <iostream>
#include <vector>
using namespace std;
int arr[1000001];
vector<int>v;
int n, m;
int main(){
	for(int i=2; i<=1000000; i++){
		if(arr[i]==0){
			v.push_back(i);
			for(int j=2; j<=1000000/i; j++){
				arr[i*j]=1;
			}
		}
	}
	arr[0]=1, arr[1]=1;
	while(1){
		cin >> n >> m;
		if(n==-1 && m==-1){
			break;
		}
		else{
			int answer=0, cnt=0;
			cout << n << " " << m << " ";
			if(n<0){
				n=0;
			}
			for(int i=0; i<v.size(); i++){
				if(v[i]>=n && v[i]<=m && arr[v[i]]==0){
					answer++;
					if(v[i]%4==1){
						cnt++;
					}
					else if(v[i]==2){
						cnt++;
					}
				}
			}
			cout << answer << " " << cnt << "\n";
		}
	}
}