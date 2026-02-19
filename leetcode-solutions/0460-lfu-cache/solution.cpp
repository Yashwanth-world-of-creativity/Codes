class LFUCache {
private:
    class Node {
    public:
        Node* prev;
        int key, val, count;
        Node* next;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
            count = 1;
            prev=next=NULL;
        }
    };

    int capacity, minFrequency;
    unordered_map<int, pair<Node*, Node*>> freq; // pair<> stores head and tail
    unordered_map<int, Node*> mp;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFrequency = 0;
    }

    int get(int key) {
        if(capacity==0) return -1;
        if (mp.count(key)) {
            Node* node = mp[key];
            int value = node->val;
            updateFrequency(node);
            return value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            Node* node = mp[key];
            node->val = value;
            updateFrequency(node);
        } else {
            if (mp.size() == capacity) {
                Node* node = freq[minFrequency].second->prev;
                mp.erase(node->key);
                removeNode(node);

                if (freq[minFrequency].first->next == freq[minFrequency].second)
                    freq.erase(minFrequency);

                delete node;
            }

            Node* node = new Node(key, value);
            mp[key] = node;

            minFrequency = 1;
            addNode(node, 1);
        }
    }

    void updateFrequency(Node* node) {
        int prevFrequency = node->count;

        removeNode(node);

        if (freq[prevFrequency].first->next == freq[prevFrequency].second) {
            freq.erase(prevFrequency);
            if (minFrequency == prevFrequency)
                minFrequency++;
        }

        addNode(node, ++node->count);
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNode(Node* node, int frequency) {
        if (!freq.count(frequency)) {
            Node* head = new Node(-1, -1);
            Node* tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            freq[frequency] = {head, tail};
        }

        Node* head = freq[frequency].first;
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
        node->prev = head;
    }
};






// class LFUCache {
// private:
//     class Node {
//     public:
//         int key, value, freq;
//         Node *prev, *next;
        
//         Node(int k, int v) {
//             key = k;
//             value = v;
//             freq = 1;
//             prev = next = NULL;
//         }
//     };
    
//     int capacity;
//     int currSize;
//     int minFreq;
    
//     unordered_map<int, Node*> keyMap;
//     unordered_map<int, pair<Node*, Node*>> freqList;
    
//     void addNode(Node* node) {
//         int f = node->freq;
        
//         if(freqList.find(f) == freqList.end()) {
//             Node* head = new Node(-1,-1);
//             Node* tail = new Node(-1,-1);
//             head->next = tail;
//             tail->prev = head;
//             freqList[f] = {head, tail};
//         }
        
//         Node* head = freqList[f].first;
        
//         node->next = head->next;
//         node->prev = head;
//         head->next->prev = node;
//         head->next = node;
//     }
    
//     void removeNode(Node* node) {
//         node->prev->next = node->next;
//         node->next->prev = node->prev;
//     }
    
//     void updateFreq(Node* node) {
//         int f = node->freq;
//         removeNode(node);
        
//         if(freqList[f].first->next == freqList[f].second && minFreq == f)
//             minFreq++;
        
//         node->freq++;
//         addNode(node);
//     }
    
// public:
//     LFUCache(int capacity) {
//         this->capacity = capacity;
//         currSize = 0;
//         minFreq = 0;
//     }
    
//     int get(int key) {
//         if(capacity == 0) return -1;
        
//         if(keyMap.find(key) == keyMap.end())
//             return -1;
        
//         Node* node = keyMap[key];
//         updateFreq(node);
//         return node->value;
//     }
    
//     void put(int key, int value) {
//         if(capacity == 0) return;
        
//         if(keyMap.find(key) != keyMap.end()) {
//             Node* node = keyMap[key];
//             node->value = value;
//             updateFreq(node);
//             return;
//         }
        
//         if(currSize == capacity) {
//             Node* tail = freqList[minFreq].second;
//             Node* nodeToRemove = tail->prev;
            
//             keyMap.erase(nodeToRemove->key);
//             removeNode(nodeToRemove);
//             currSize--;
//         }
        
//         Node* newNode = new Node(key, value);
//         minFreq = 1;
        
//         keyMap[key] = newNode;
//         addNode(newNode);
//         currSize++;
//     }
// };

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
