#include<iostream>
#include<map>
using namespace std;
struct Node{
    int key , val , cnt;
    Node* next;
    Node* prev;
    Node(int k , int v)
    {
       key = k;
       val = v;
       cnt = 1;
    }
};
struct List{
    Node* head;
    Node* tail;
    int size;
    List()
    {  
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void addFront(Node* node)
    {
        Node* temp = head->next;
        node->next = temp;
        node->prev=head;
        head->next = node;
        temp->prev = node;
        size++;
    }
    void removeNode(Node* node)
    {
        Node* delprev = node->prev;
        Node* delnext = node->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};
class LFUCache {
public:
    map<int,Node*>keyNode;
    map<int,List*>freqList;
    int maxCacheSize;
    int minFreq;
    int curSize;
    LFUCache(int capacity) {
        maxCacheSize = capacity;
        minFreq = 0;
        curSize = 0;
    }
    void updateFreq(Node* node)
   {
    int oldFreq = node->cnt;

    keyNode.erase(node->key);
    freqList[oldFreq]->removeNode(node);

    if (oldFreq == minFreq && freqList[oldFreq]->size == 0)
    {
        minFreq++;
    }

    List* nextHigherFreq;
    if (freqList.find(oldFreq + 1) != freqList.end())
    {
        nextHigherFreq = freqList[oldFreq + 1];
    }
    else
    {
        nextHigherFreq = new List();
        freqList[oldFreq + 1] = nextHigherFreq;
    }

    node->cnt++;
    nextHigherFreq->addFront(node);
    keyNode[node->key] = node;
    }
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end())
        {
            Node* node = keyNode[key];
            int value = node->val;
            updateFreq(node);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxCacheSize == 0) return;
        if(keyNode.find(key)!=keyNode.end())
        {
            Node* node = keyNode[key];
            node->val = value;
            updateFreq(node);
        }
        else
        {
          if(curSize==maxCacheSize)
          {
            List* list = freqList[minFreq];
            keyNode.erase(list->tail->prev->key);
            freqList[minFreq]->removeNode(list->tail->prev);
            curSize--;
          }
          curSize++;
          minFreq = 1;
          List* listfreq = new List();
          if(freqList.find(minFreq)!=freqList.end())
          {
            listfreq = freqList[minFreq];
          }
          Node* node = new Node(key,value);
          listfreq->addFront(node);
          keyNode[key]=node;
          freqList[minFreq]=listfreq;
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 **/
