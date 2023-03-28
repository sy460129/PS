#include <iostream>
#include <deque>
using namespace std;
bool c;
int main(){
    int n, t, cnt=0;
    string s;
    cin >> n >> t >> s;
    deque<char>d;
    for(int i=0; i<t; i++){
        d.push_back(s[i]);
        c=true;
        if(d.size()==n*2+1){
            for(int j=0; j<d.size(); j++){
                if((j%2==0 && d[j]!='I') || (j%2!=0 && d[j]!='O')){
                    c=false;
                    break;
                }
            }
            if(c){
                cnt++;
            }
            d.pop_front();
            while(!d.empty() && d.front()=='O') d.pop_front();
        }
    }
    cout << cnt;
}