#include <iostream>
#include <vector>
using namespace std;
struct node{
	int data;
	node* left;
	node* right;
	node(int d, node* l, node* r){
		this->data=d;
		this->left=l;
		this->right=r;
	}
};
class Tree{
public:
	node* getRoot(){
		return root;
	}
	node* addNode(node* temp, int d){
		if(temp==NULL){
			temp=new node(d,NULL,NULL);
			if(root==NULL) root=temp;
		}
		else{
			if(d<temp->data){
				temp->left=addNode(temp->left,d);
			}
			else temp->right=addNode(temp->right,d);
		}
		return temp;
	}
	void post(node* curNode){
		if(curNode->left!=NULL){
			post(curNode->left);
		}
		if(curNode->right!=NULL){
			post(curNode->right);
		}
		cout << curNode->data << "\n";
	}
private:
	node* root=NULL;
};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int x;
	Tree tree;
	while(cin >> x){		
		tree.addNode(tree.getRoot(), x);
	}
	tree.post(tree.getRoot());
}