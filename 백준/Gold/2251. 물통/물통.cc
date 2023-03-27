#include <iostream>
#include <queue>
#include <tuple>
#include <set>
using namespace std;
using t = tuple<int, int, int>;
int a, b, c, ss;
bool check[201][201][201];
set<int>ans;
queue<t>q;
void bfs() {
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = get<0>(cur);
        int y = get<1>(cur);
        int z = get<2>(cur);
        if(check[x][y][z]) continue;
        check[x][y][z]=true;
        if(x==0) ans.insert(z);
        if(z!=0){
            if(x+z<=a) q.push({z+x,y,0});
            else q.push({a,y,z+x-a});
            if(y+z<=b) q.push({x,z+y,0});
            else q.push({x,b,z+y-b});
        }
        if(x!=0){
            if(x+z<=c) q.push({0,y,z+x});
            else q.push({x+z-c,y,c});
            if(x+y<=b) q.push({0,x+y,z});
            else q.push({x+y-b,b,z});
        }
        if(y!=0){
            if(y+z<=c) q.push({x,0,z+y});
            else q.push({x,y+z-c,c});
            if(x+y<=a) q.push({x+y,0,z});
            else q.push({a,x+y-a,z});
        }
    }
}
int main() {
    cin >> a >> b >> c;
    q.push({ 0,0,c });
    bfs();
    for (auto it = ans.begin(); it != ans.end(); it++) {
        cout << *it << " ";
    }
}