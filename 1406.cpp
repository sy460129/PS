#include <iostream>
using namespace std;
struct node {
    char data;
    node* prev;
    node* next;
};
class List {
public:
    void AddNode(char c) {
        node* temp = new node;
        temp->data = c;
        if (head == nullptr) {
            head = temp;
            tail = temp;
            cursor = tail;
            cursor->next = nullptr;
        }
        else {
            if (cursor == nullptr) {
                temp->next = head;
                head->prev = temp;
                head = temp;
                cursor = head;
            }
            else if (cursor == tail) {
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
                cursor = tail;
                cursor->next = nullptr;
            }
            else {
                temp->prev = cursor;
                temp->next = cursor->next;
                cursor->next = temp;
                temp->next->prev = temp;
                cursor = temp;
            }
        }
    }
    void Cursor_L() {
        if (cursor != head && cursor!=nullptr) {
            cursor = cursor->prev;
        }
        else {
            cursor = nullptr;
        }
    }
    void Cursor_D() {
        if (cursor == nullptr) {
            if (head != nullptr) {
                cursor = head;
            }
        }
        else if (cursor != tail) {
            cursor = cursor->next;
        }
    }
    void DeleteNode() {
        if (cursor == head) {
            if (cursor != nullptr) {
                if (cursor->next == nullptr) {
                    head = nullptr;
                }
                else {
                    head = cursor->next;
                }
                cursor = nullptr;
            }
        }
        else if (cursor == tail) {
            tail = cursor->prev;
            tail->next = nullptr;
            cursor = tail;
            cursor->next = nullptr;
        }
        else if(cursor!=nullptr) {
            node* temp = cursor->prev;
            temp->next = cursor->next;
            temp->next->prev = cursor->prev;
            cursor = temp;
        }
    }
    void Print() {
        while (head!=nullptr) {
            cout << head->data;
            head = head->next;
        }
    }
private:
    node* head = nullptr;
    node* tail = nullptr;
    node* cursor = nullptr;
};
int main() {
    string s;
    List list;
    int n;
    char x, y;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        list.AddNode(s[i]);
    }
    cin >> n;
    while (n--) {
        cin >> x;
        if (x == 'P') {
            cin >> y;
            list.AddNode(y);
        }
        else {
            if (x == 'L') {
                list.Cursor_L();
            }
            else if (x == 'D') {
                list.Cursor_D();
            }
            else {
                list.DeleteNode();
            }
        }
    }
    list.Print();
}