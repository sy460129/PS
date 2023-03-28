#include <iostream>
#include <vector>
#define MAX 999999999999999999
using namespace std;
bool check1, check2;
int main(){
    long long i=-(MAX+2), j=MAX+2, t;
    int n, ans; cin >> n;
    char c;
    for(int k=1; k<=n; k++){
        cin >> t >> c;
        if(c=='^') i=max(i, t);
        else if(c=='v') j=min(j, t);
        if(i>=j-1 && !check1){
            check1=true;
            ans=k;
        }
        else if(j-i==2 && !check1 && !check2){
            check2=true;
            ans=k;
        }
    }
    if(check1) cout << "Paradox!\n" << ans;
    else if(check2) cout << "I got it!\n" << ans;
    else cout << "Hmm...";
}