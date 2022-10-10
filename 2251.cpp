#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
bool visit[201];
bool check[201][201][201];
queue<tuple<int,int,int>>qu;
int a, b, c;
void bfs(){
    while(!qu.empty()){
        auto cur=qu.front(); qu.pop();
        int x=get<0>(cur);
        int y=get<1>(cur);
        int z=get<2>(cur);
        int p=x, q=y, r=z;
        if(r>=(a-p)){
            r-=(a-p);
            p=a;
            if(!check[p][q][r]){
                check[p][q][r]=true;
                qu.push({p,q,r});
                visit[r]=true;
            }
            if(r>=(b-q)){
                r-=(b-q);
                q=b;
                if(!check[p][q][r]){
                    check[p][q][r]=true;
                    qu.push({p,q,r});
                    visit[r]=true;
                }
            }
            else{
                q+=r;
                r=0;
                if(!check[p][q][r]){
                    check[p][q][r]=true;
                    qu.push({p,q,r});
                    visit[r]=true;
                }
            }
        }
        else{
            p+=r;
            r=0;
            if(!check[p][q][r]){
                check[p][q][r]=true;
                qu.push({p,q,r});
                visit[r]=true;
            }
        }
        int p=x, q=y, r=z;
        if(r>=(b-q)){
            r-=(b-q);
            q=b;
            if(!check[p][q][r]){
                check[p][q][r]=true;
                qu.push({p,q,r});
                visit[r]=true;
            }
            if(r>=(a-p)){
                r-=(a-p);
                p=a;
                if(!check[p][q][r]){
                    check[p][q][r]=true;
                    qu.push({p,q,r});
                    visit[r]=true;
                }
            }
            else{
                p+=r;
                r=0;
                if(!check[p][q][r]){
                    check[p][q][r]=true;
                    qu.push({p,q,r});
                    visit[r]=true;
                }
            }
        }
        else{
            q+=r;
            r=0;
            if(!check[p][q][r]){
                check[p][q][r]=true;
                qu.push({p,q,r});
                visit[r]=true;
            }
        }
        
    }
}
int main(){
    cin >> a >> b >> c;
    qu.push({0,0,c});
    check[0][0][c]=true;
    bfs();
}