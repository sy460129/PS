#include <iostream>
#include <string>
using namespace std;
using ull=unsigned long long;
ull arr1[10000001]={};
ull col[100001]={};
ull n, m;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>col[i];
    }//일단 각 열에 몇개씩 들어가는지를 받는다.
    for(ull i=0;i<col[0];i++){
        cin>>arr1[i];
    }//맨 왼쪽 1열에 생긴 강을 받는다. 
    for(ull i=1;i<m;i++){ //2열부터 시작
        ull arr2[10000000]={};
        ull arr3[10000000]={};
        for(ull j=0;j<col[i];j+=2){ // 물 시작점 끝점 2개씩받고
            cin>>arr2[j]>>arr2[j+1];
            int idx=0;
            for(ull k=0;k<col[i-1];k+=2){
                if(arr1[k]<=arr2[j+1] || arr1[k+1]>=arr2[j]){//arr3에 arr2중에서 왼쪽에서 넘어올수있는거만 집어넣고
                    arr3[idx]=arr2[j];
                    arr3[idx+1]=arr2[j+1];
                    idx++;
                    idx++;
                }
            }
            if(idx==0){
                cout<<"NO";
                break;
            }   
            else{
                for(ull k=0;k<col[i-1];k++){//왼쪽으로 한칸씩 밀기위한 빌드업
                    arr1[k]=arr3[k];
                }
            }        
            
        }


    }
    cout<<"YES";
    return 0;
}