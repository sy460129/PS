#include <iostream>
using namespace std;
int n, i, t, x;
int ask(int a){
    cout << "? " << a << "\n";
    cin >> x;
    return x;
}
int main(){
    cin >> n;
    t=n, i=1;
    int a=ask(i);
    int b=ask(t);
    if(a==0){
        cout << "= " << i;
    }
    else if(b==0){
        cout << "= " << t;
    }
    else{
        while(i<=t){
            int m=(i+t)/2;
            int k=ask(m);
            if(k==1){
                t=m-1;
            }
            else if(k==-1){
                i=m+1;
            }
            else{
                cout << "= " << m;
            }
        }
    }
}