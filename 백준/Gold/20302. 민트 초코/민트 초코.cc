#include <iostream>
#include <cmath>
using namespace std;
int check[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	char c;
	int n, s; cin >> n;
	for(int i=0; i<n; i++){
        int j=2;
		if(i==0){
			cin >> s;
			if(s<0) s*=-1;
            while(j<=sqrt(s)){
                if(s%j==0){
					check[j]++;
                    s/=j;
				}
                else j++;
            }
            check[s]++;
		}
		else{
			cin >> c >> s;
			if(s<0) s*=-1;
			if(c=='*'){
                while(j<=sqrt(s)){
                    if(s%j==0){
				    	check[j]++;
                        s/=j;
				    }
                    else j++;
                }
                check[s]++;
			}
			else{
				while(j<=sqrt(s)){
                    if(s%j==0){
				    	check[j]--;
                        s/=j;
				    }
                    else j++;
                }
                check[s]--;
			}
		}
        if(s==0){
            cout << "mint chocolate";
            return 0;
        }
	}
	for(int i=2; i<=100000; i++){
		if(check[i]<0){
			cout << "toothpaste";
			return 0;
		}
	}
	cout << "mint chocolate";
}