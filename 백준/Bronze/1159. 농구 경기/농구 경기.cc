#include <iostream>
using namespace std;
int arr[26];
bool c;
int main(){
	int n;
	string s;
	cin >> n;
	while(n--){
		cin >> s;
		arr[s[0]-'a']++;
	}
	for(int i=0; i<26; i++){
		if(arr[i]>=5){
			cout << (char)(i+'a');
			c=true;
		}
	}
	if(!c){
		cout << "PREDAJA";
	}
}