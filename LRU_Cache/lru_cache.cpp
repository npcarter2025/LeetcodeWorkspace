#include <unordered_map>
#include <iostream>
using namespace std;

class Node {
    public:
        int key;
        int value;
        Node* next;
        Node* prev;
    
        Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
    
    
    };
    
    class LRUCache {
    
    private:
        int capacity;
        std::unordered_map<int, Node*> cache;
    
        Node* head;
        Node* tail;
    
        void remove(Node* node) {
            Node* prev = node->prev;
            Node* next = node->next;
            prev->next = next;
            next->prev = prev;
        }
    
        void insert(Node* node) {
            Node* prev = tail->prev;
            Node* next = tail;
    
            prev->next = node;
            next->prev = node;
    
            node->prev = prev;
            node->next = next;
        }
    
    public:
        LRUCache(int capacity) : capacity(capacity) {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
        }
        ~LRUCache() {
            Node* current = head;
            while (current != nullptr) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }
        
        int get(int key) {
            if (cache.empty()) {
                return -1;
            }
    
            auto it = cache.find(key);
            if (it != cache.end()) {
                Node* node = it->second;
                remove(node);
                insert(node);
                return node->value;
            }
            return -1;
            
        }
        
        void put(int key, int value) {
            auto iter = cache.find(key);
            if (iter != cache.end()) {
                remove(iter->second);
            }
    
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            insert(newNode);
    
            if (cache.size() > capacity) {
                Node* lru = head->next;
                remove(lru);
                cache.erase(lru->key);
                delete lru;
            }
        }
    };
    
    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */