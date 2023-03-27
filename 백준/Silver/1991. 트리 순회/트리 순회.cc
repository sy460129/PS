#include <iostream>
using namespace std;
int lc[30];
int rc[30];
void pre(int t){
    cout << char(t+'A');
    if(lc[t]!=0) pre(lc[t]);
    if(rc[t]!=0) pre(rc[t]);
}
void in(int t){
    if(lc[t]!=0) in(lc[t]);
    cout << char(t+'A');
    if(rc[t]!=0) in(rc[t]);
}
void post(int t){
    if(lc[t]!=0) post(lc[t]);
    if(rc[t]!=0) post(rc[t]);
    cout << char(t+'A');
}
int main(){
    int n; cin >> n;
    char a, b, c;
    for(int i=0; i<n; i++){
        cin >> a >> b >> c;
        if(b!='.') lc[a-'A']=b-'A';
        if(c!='.') rc[a-'A']=c-'A';
    }
    pre(0);
    cout << "\n";
    in(0);
    cout << "\n";
    post(0);
}