#define HASH_SIZE 1000
typedef struct Node {
    int key;
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct HashNode {
    int key;
    Node* value;
    struct HashNode* next;
} HashNode;


typedef struct {
    int capacity;
    int size;

    Node* head;
    Node* tail;
    HashNode* hash_table[HASH_SIZE];
    
} LRUCache;

int hash(int key) {
    return key % HASH_SIZE;
}

Node* createNode(int key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        exit(1);
    }

    node->key = key;
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

HashNode* createHashNode(int key, Node* value) {
    HashNode* hashNode = (HashNode*)malloc(sizeof(HashNode));
    
    hashNode->key = key;
    hashNode->value = value;
    hashNode->next = NULL;
    return hashNode;
}

Node* findInHash(LRUCache* cache, int key) {
    int index = hash(key);
    HashNode* curr = cache->hash_table[index];
    while (curr != NULL) {
        if (curr->key == key) {
            return curr->value;
        }
        curr = curr->next;
    }
    return NULL;
}

void insertInHash(LRUCache* cache, int key, Node* value) {
    int index = hash(key);

    HashNode* curr = cache->hash_table[index];
    while (curr != NULL) {
        if (curr->key == key) {
            curr->value = value;
            return;
        }
        curr = curr->next;
    }

    HashNode* newHashNode = createHashNode(key, value);
    newHashNode->next = cache->hash_table[index];
    cache->hash_table[index] = newHashNode;

}

void removeFromHash(LRUCache* cache, int key) {
    int index = hash(key);
    HashNode* current = cache->hash_table[index];
    HashNode* prev = NULL;

    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                cache->hash_table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void removeNode(LRUCache* cache, Node* node) {
    Node* prev = node->prev;
    Node* next = node->next;
    prev->next = next;
    next->prev = prev;
}

void insertNode(LRUCache* cache, Node* node) {
    Node* prev = cache->tail->prev;
    Node* next = cache->tail;

    prev->next = node;
    next->prev = node;

    node->prev = prev;
    node->next = next;
}



LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    if (cache == NULL) {
        printf("mem failure\n");
        exit(1);
    }

    cache->capacity = capacity;
    cache->size = 0;

    for (int i = 0; i < HASH_SIZE; i++) {
        cache->hash_table[i] = NULL;
    }

    cache->head = createNode(0, 0);
    cache->tail = createNode(0, 0);
    cache->head->next = cache->tail;
    cache->tail->prev = cache->head;

    return cache;
}

int lRUCacheGet(LRUCache* cache, int key) {
    Node* node = findInHash(cache, key);
    if (node == NULL) {
        return -1;
    }
    removeNode(cache, node);
    insertNode(cache, node);
    return node->value;
}

void lRUCachePut(LRUCache* cache, int key, int value) {
    Node* existingNode = findInHash(cache, key);

    if (existingNode != NULL) {
        existingNode->value = value;
        removeNode(cache, existingNode);
        insertNode(cache, existingNode);
    } else {
        Node* newNode = createNode(key, value);
        insertInHash(cache, key, newNode);
        insertNode(cache, newNode);
        cache->size++;

        if(cache->size > cache->capacity) {
            Node* lru = cache->head->next;
            removeNode(cache, lru);
            removeFromHash(cache, lru->key);
            free(lru);
            cache->size--;
        }
    }
}

void lRUCacheFree(LRUCache* cache) {
    Node* current = cache->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }

    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* current = cache->hash_table[i];
        while (current != NULL) {
            HashNode* next = current->next;
            free(current);
            current = next;
        }
    }
    free(cache);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/