#include<iostream>
#include<unordered_map>
using namespace std;
struct Node{
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(): key(0),val(0),next(nullptr),prev(nullptr){}
    Node(int k , int v): key(k),val(v),next(nullptr),prev(nullptr){}
};
class LRUCache {
public:
    unordered_map <int,Node*> mp;
    int cap;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    //function to delete node
    void deleteNode(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insertAtHead(Node* node)
    {
        node->next = head->next;
        head->next = node;
        node->next->prev = node;
        node->prev = head;
    }
    LRUCache(int capacity) {
        cap = capacity;
        mp.clear();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Node* node = mp[key];
        deleteNode(node);
        insertAtHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            Node* node = mp[key];
            node->val = value;
            deleteNode(node);
            insertAtHead(node);
        }
        else
        {
            if(mp.size()==cap)
            {
                Node* node = tail->prev;
                mp.erase(node->key);
                deleteNode(node);
            }
            Node* node = new Node(key,value);
            mp[key]=node;
            insertAtHead(node);
        }
    }
};
int main()
{
    int capacity;
    cout<<"Enter capacity of LRU Cache: ";
    cin>>capacity;
    LRUCache obj(capacity);
    int op;
    cout<<"enter operation (1-get , 2-put): ";
    cin>>op;
    int k , v;
    switch (op)
    {
        case 1 : cout<<"enter key: ";
                 cin>>k;
                 cout<<"value= "<<obj.get(k)<<endl;
                 break;
        case 2: cout<<"enter key: ";
                cin>>k;
                cout<<"enter value to put: ";
                cin>>v;
                obj.put(k,v);
                cout<<"Cache updated successfully!"<<endl;
                break;
      default : cout<<"enter correct operation."<<endl;
    }
    return 0;

}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */