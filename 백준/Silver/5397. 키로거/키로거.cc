#include <iostream>
using namespace std;
struct node{
    char data;
    node* prev;
    node* next;
};
class List{
public:
    void AddNode(char d){
        node* temp=new node;
        temp->data=d;
        if(head==nullptr){
            head=temp;
            tail=temp;
            cursor=tail;
            cursor->next=nullptr;
        }
        else{
            if(cursor==nullptr){
                temp->next=head;
                head->prev=temp;
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
                cursor->next->prev=temp;
                temp->next=cursor->next;
                cursor->next=temp;
                temp->prev=cursor;
                cursor=temp;
            }
        }
    }
    void Cursor_L(){
        if(cursor!=nullptr){
            if(cursor==head) cursor=nullptr;
            else cursor=cursor->prev;
        }
    }
    void Cursor_R(){
        if(cursor==nullptr){
            cursor=head;
        }
        else if(cursor!=tail){
            cursor=cursor->next;
        }
    }
    void DeleteNode(){
        if(cursor!=nullptr){
            if(cursor==head){
                if(cursor->next==nullptr){
                    head=nullptr;
                }
                else{
                    head=cursor->next;
                    head->prev=nullptr;
                }
                cursor=nullptr;
            }
            else if(cursor==tail){
                tail=cursor->prev;
                tail->next=nullptr;
                cursor=tail;
            }
            else{
                node* temp=cursor->prev;
                temp->next=cursor->next;
                temp->next->prev=cursor->prev;
                cursor=temp;
            }
        }
    }
    void setHead(){
        cursor=head;
    }
    void Print(){
        while(1){
            if(cursor==tail){
                cout << cursor->data << "\n";
                break;
            }
            else{
                cout << cursor->data;
                cursor=cursor->next;
            }
        }
    }
private:
    node* head=nullptr;
    node* tail=nullptr;
    node* cursor=nullptr;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        List list;
        string s;
        cin >> s;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='<'){
                list.Cursor_L();
            }
            else if(s[i]=='>'){
                list.Cursor_R();
            }
            else if(s[i]=='-'){
                list.DeleteNode();
            }
            else{
                list.AddNode(s[i]);
            }
        }
        list.setHead();
        list.Print();
    }
}