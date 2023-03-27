#include <iostream>
using namespace std;
bool visit[1000000];
bool check[10];
bool ch, cn, cx;
int n, x, t, c, s, p, cnt;
int main(){
    cin >> c >> n;
    while(n--){
        cin >> x;
        check[x]=true;
    }
    visit[100]=true;
    if(!check[0]) visit[0]=true;
    if(visit[0] && c==0){
        cout << 1;
        return 0;
    }
    for(int i=1; i<=999999; i++){
        x=i;
        ch=true;
        while(x!=0){
            t=x%10;
            x/=10;
            if(check[t]){
                ch=false;
                break;
            }
        }
        if(ch) visit[i]=true;
    }
    t=0;
    n=c, x=c;
    while(1){
        if(n<=999999 && visit[n]){
            s=n;
            while(s!=0){
                s/=10;
                t++;
            }
            cn=true;
        }
        if(x>=0 && visit[x]){
            s=x;
            while(s!=0){
                s/=10;
                p++;
            }
            p=max(1,p);
            cx=true;
        }
        if(cn || cx) break;
        n++, x--;
    }
    if(cn && cx){
        cout << min(n-c+t, min(c-x+p, abs(100-c)));
    }
    else{
        if(cn) cout << min(n-c+t, abs(100-c));
        else cout <<  min(c-x+p, abs(100-c));
    }
}