#include <iostream>
using namespace std;
int arr[10][10];
pair<int,int>p;
int main(){
    int res=-1;
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            cin >> arr[i][j];
            if(arr[i][j]>res){
                res=arr[i][j];
                p={i,j};
            }
        }
    }
    cout << res << "\n" << p.first << " " << p.second;
}