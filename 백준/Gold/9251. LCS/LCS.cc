#include <iostream>
using namespace std;
int LCS[1001][1001];
int main(){
	string s, c;
	cin >> s >> c;
	for(int i=1; i<=s.length(); i++){
		for(int j=1; j<=c.length(); j++){
			if(s[i-1]==c[j-1]){
				LCS[i][j]=LCS[i-1][j-1]+1;
			}
			else{
				LCS[i][j]=max(LCS[i][j-1], LCS[i-1][j]);
			}
		}
	}
	cout << LCS[s.length()][c.length()];
}