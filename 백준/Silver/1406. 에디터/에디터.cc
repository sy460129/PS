#include <iostream>
using namespace std;
struct node{
	char data;
	node* next;
	node* prev;
};
class LinkedList{
public:
	void AddNode(char d){
		node* temp=new node;
		temp->data=d;
		if(head==nullptr){
			head=temp;
			tail=temp;
			cursor=tail;
		}
		else if(cursor==nullptr){
			head->prev=temp;
			temp->next=head;
			head=temp;
			cursor=head;
		}
		else if(cursor==tail){
			tail->next=temp;
			temp->prev=tail;
			tail=temp;
			cursor=tail;
		}
		else{
			temp->next=cursor->next;
			cursor->next=temp;
			temp->next->prev=temp;
			temp->prev=cursor;
			cursor=temp;
		}
	}
	void L(){
		if(cursor!=nullptr){
			if(cursor==head) cursor=nullptr;
			else cursor=cursor->prev;
		}
	}
	void D(){
		if(cursor!=tail){
			if(cursor==nullptr) cursor=head;
			else cursor=cursor->next;
		}
	}
	void B(){
		if(cursor!=nullptr){
			node* temp=cursor;
			if(cursor==tail){
				tail=temp->prev;
				delete[] temp;
				cursor=tail;
			}
			else if(cursor==head){
				head=head->next;
				delete[] temp;
				cursor=nullptr;
			}
			else{
				cursor->prev->next=cursor->next;
				cursor->next->prev=cursor->prev;
				cursor=temp->prev;
				delete[] temp;
			}
		}
	}
	void Print(){
		node* c=head;
		while(c!=tail){
			cout << c->data;
			c=c->next;
		}
		cout << c->data;
	}
private:
	node* head=nullptr;
	node* tail=nullptr;
	node* cursor=nullptr;
};
int main(){
	LinkedList list;
	string s;
	int n;
	char c, x;
	cin >> s >> n;
	for(int i=0; i<s.length(); i++) list.AddNode(s[i]);
	while(n--){
		cin >> c;
		if(c=='P'){
			cin >> x;
			list.AddNode(x);
		}
		else if(c=='L') list.L();
		else if(c=='D') list.D();
		else if(c=='B') list.B();
	}
	list.Print();
}