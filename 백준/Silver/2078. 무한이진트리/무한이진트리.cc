#include <iostream>
using namespace std;
int x, y, cl, cr;
int main(){
    cin >> x >> y;
    while(x!=y){
        if(x>y) x-=y, cl++;
        else y-=x, cr++;
        if(x==1 || y==1){
            if(x==1) cr+=y-1;
            else cl+=x-1;
            break;
        }
    }
    cout << cl << " " << cr;
}