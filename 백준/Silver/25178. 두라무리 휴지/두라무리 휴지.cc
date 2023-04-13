#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<char>q, q2;
vector<char>v1, v2;
int arr[26];
int brr[26];
int main(){
	int n, x=0, t=0;
	char c, s;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> c;
		arr[c-'a']++;
		v1.push_back(c);
	}
	for(int i=0; i<n; i++){
		cin >> c;
		brr[c-'a']++;
		v2.push_back(c);
	}
	for(int i=0; i<26; i++){
		if(arr[i]!=brr[i]){
			cout << "NO";
			return 0;
		}
	}
	if(v1[0]!=v2[0] || v1.back() != v2.back()){
		
		cout << "NO";
		return 0;
	}
	while(1){
		while(1){
			if(x>=v1.size()){
				break;
			}
			c=v1[x];
			if(c=='a' || c=='e'|| c=='i' || c=='o' || c=='u'){
				x++;
			}
			else{
				break;
			}
		}
		while(1){
			if(t>=v2.size()){
				break;
			}
			s=v2[t];
			if(s=='a' || s=='e'|| s=='i' || s=='o' || s=='u'){
				t++;
			}
			else{
				break;
			}
		}
		if(c!=s){
			cout << "NO";
			return 0;
		}
		x++, t++;
		if(x>=v1.size() || t>=v2.size()){
			break;
		}
	}
	cout << "YES";
}