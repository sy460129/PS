#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
queue<pair<string,int>>q;
int arr[11][26];
string x;
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    sort(words.begin(), words.end());
    for(int i=0; i<words[0].length(); i++){
        for(int j=0; j<words.size(); j++){
            arr[i][words[j][i]-'a']=1;
        }
    }
    q.push({begin,0});
    while(!q.empty()){
        string word=q.front().first;
        int cnt=q.front().second;
        q.pop();
        for(int i=0; i<word.length(); i++){
            for(int j=0; j<26; j++){
                if(arr[i][j]){
                    x=word;
                    x[i]=(char)(j+'a');
                    if(x==target){
                        return cnt+1;
                    }
                    auto it=find(words.begin(), words.end(), x);
                    if(it!=words.end()){
                        q.push({*it,cnt+1});
                        words.erase(it);
                    }
                }
            }
        }
    }
    return answer;
}