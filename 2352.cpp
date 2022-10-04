#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int>v;
    int n, x;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        if(v.empty() || x>v.back()) v.push_back(x);
        else{
            auto it=lower_bound(v.begin(), v.end(), x)-v.begin();
            v[it]=x;
        }
    }
    cout << v.size();
}