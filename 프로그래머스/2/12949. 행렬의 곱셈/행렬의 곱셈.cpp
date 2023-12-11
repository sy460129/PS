#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size());
    int ans;
    for(int i=0; i<arr1.size(); i++){
        for(int j=0; j<arr2[0].size(); j++){
            ans=0;
            for(int l=0; l<arr1[i].size(); l++){
                ans+=arr1[i][l]*arr2[l][j];
            }
            answer[i].push_back(ans);
        }
    }
    return answer;
}