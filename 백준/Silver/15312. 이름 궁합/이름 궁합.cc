#include <iostream>
using namespace std;
int alpha[]={3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
int arr[2001];
int brr[2001];
int main(){
	string s, c; cin >> s >> c;
	for(int i=0; i<s.length(); i++) arr[i]=alpha[s[i]-'A'];
	for(int i=0; i<c.length(); i++) brr[i]=alpha[c[i]-'A'];
	int t=c.length()*2, l;
	t--, l=t;
	while(1){
		int p=0, q=0;
		while(l--){
			if(p==q) arr[p]=(arr[p]+brr[q])%10, p++;
			else brr[q]=(arr[p]+brr[q])%10, q++;
		}
		t--;
		l=t;
		if(t==1){
			cout << arr[0] << brr[0];
			return 0;
		}
	}
}