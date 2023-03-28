#include <iostream>
#define rep(i, a, b) for(int i=a; i<b; i++)
using namespace std;
string ans, s, x, c;
string arr[26]={"aespa", "baekjoon", "cau", "debug", "edge", "firefox", "golang", "haegang", "iu", "java", "kotlin", "lol", "mips", "null", "os", "python", "query", "roka", "solvedac", "tod", "unix", "virus", "whale", "xcode", "yahoo", "zebra"};
int main(){
    cin >> s;
    rep(i, 0, s.length()){
        x+=s[i];
        if(x==arr[x[0]-'a']){
            ans+=x[0], x=c; 
        }
    }
    x==c ? cout << "It's HG!\n" << ans : cout << "ERROR!";
}