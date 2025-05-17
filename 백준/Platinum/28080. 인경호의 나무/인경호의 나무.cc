#include <iostream>
#include <vector>
#define MAX 1000000007
using namespace std;
using ull=unsigned long long;
vector<int>ans;
struct node{
	int value;
	node* left=NULL;
	node* right=NULL;
};
void inorder(node* x){
	if(x->left) inorder(x->left);
	ans.push_back(x->value);
	if(x->right) inorder(x->right);
}
node* v[1001];
ull dp[2001][2001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for(int i=0; i<=2000; i++){
		for(int j=0; j<=i; j++){
			if(i==j || j==0) dp[i][j]=1;
			else dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%MAX;
		}
	}
	int n, m, val, l, r; cin >> n >> m;
	for(int i=1; i<=n; i++){
		v[i] = new node();
	}
	for(int i=1; i<=n; i++){
		cin >> val >> l >> r;
		v[i]->value=val;
		if(l!=-1) v[i]->left=v[l];
		if(r!=-1) v[i]->right=v[r];
	}
	inorder(v[1]);
	ans.push_back(m+1);
	int s=0, cnt=0;
	ull res=1;
	for(int i=0; i<ans.size(); i++){
		if(ans[i]!=-1){
			if(cnt){
				res*=dp[ans[i]-s-1][cnt];
				res%=MAX;
				cnt=0;
			}
			s=ans[i];
		}
		else cnt++;
	}
	cout << res;
}