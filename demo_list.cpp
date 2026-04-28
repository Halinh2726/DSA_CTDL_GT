#include <iostream>

using namespace std;

struct LinkedList {
    struct Node {
        string data;
        Node* next;
        Node(){}
        Node(string _data) {
            data = _data;
            next = nullptr;
        }
    };

    Node* head = nullptr;

    void addFirst(string v) {
        Node* new_node = new Node();
        new_node->data = v;
        new_node->next = head;
        head = new_node;
    }

    void printList(){
        for(Node* p = head; p != NULL; p = p->next) {
            cout << p->data << " ";
        }
        cout << endl;
    }

    void addLast(string v) {
        Node* new_node = new Node();
        new_node->data = v;
        new_node->next = nullptr;
        if(head == nullptr) {
            head = new_node;
        }
        else {
            Node* p = head;
            while(p->next != nullptr) {
                p = p->next;
            }
            p->next = new_node;
        }
    }

    void insertAfter(string pivot, string newKey) {
        Node* new_node = new Node();
        new_node->data = newKey;
        new_node->next = nullptr;
        if(head == nullptr) {
            head = new_node;
        }
        else {
            Node* p = head;
            while(p != nullptr && p->data != pivot) {
                p = p->next;
            }
            if(p != nullptr) {
                new_node->next = p->next;
                p->next = new_node;
            }
        }
    }

    void removeFirst() {
        if(head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void removeLast() {
        if(head != nullptr) {
            if(head->next == nullptr) {
                delete head;
                head = nullptr;
            }
            else {
                Node* p = head;
                while(p->next->next != nullptr) {
                    p = p->next;
                }
                delete p->next;
                p->next = nullptr;
            }
        }
    }

    bool searchByKey(string key) {
        Node* p = head;
        while(p != nullptr) {
            if(p->data == key) {
                return true;
            }
            p = p->next;
        }
        return false;
    }

    void removeByKey(string key) {
        if(head != nullptr) {
            if(head->data == key) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            else {
                Node* p = head;
                while(p->next != nullptr && p->next->data != key) {
                    p = p->next;
                }
                if(p->next != nullptr) {
                    Node* temp = p->next;
                    p->next = p->next->next;
                    delete temp;
                }
            }
        }
    }
};

int main() {
    LinkedList demoList;
    demoList.addFirst("1");
    demoList.addFirst("2");
    demoList.addFirst("3");
    demoList.printList();
    cout << demoList.head << endl;
    cout << demoList.head->next << endl;
    cout << demoList.head->next->next << endl;

//    demoList.removeLast);



//    demoList.addLast("1");
//    demoList.addLast("2");
//    demoList.addLast("3");
//    demoList.printList();
//    demoList.insertAfter("5", "4");




//    if(demoList.searchByKey("1")) {
//        cout << "YES" << endl;
//    }
//    else
//        cout << "NO" << endl;



    return 0;
}
