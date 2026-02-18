
class LRUCache {
    class Node {
        public:
        Node* prev, *next;
        int key,value;
        Node(int key,int value){
            this->key=key;
            this->value=value;
            
        }
    };
    int capacity,currSize;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int,Node*>mp;

    void deleteNode(Node * node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
     void put_front(Node * node){
        node->next=head->next;
        node->prev=head;
        node->next->prev=node;
        head->next=node;
    }
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        this->currSize=0;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node *node = mp[key];// address of value i.e key
            int val=node->value;
            deleteNode(node);
            put_front(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
         if(mp.find(key)!=mp.end()){// no size diff
            Node *node=mp[key];
            node->value=value;
            deleteNode(node);
            put_front(node);
            return;
         }
         if(currSize== capacity){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
            currSize--;
            
         }
         put_front(new Node(key,value));
         mp[key]=head->next;
         currSize++;
    }
};



//Brute force 
// #define pii pair<int,int>
// class LRUCache {
//     private:
//     int capacity;
//     vector<pii> cache;
// public:
//     LRUCache(int capacity) {
//         this->capacity=capacity;
//     }
    
//     int get(int key) {
//         for(int i{0},n=cache.size();i<n;i++){
//             if(cache[i].first==key){
//                 int val=cache[i].second;
              //  pii temp=cache[i];// before getting value we have to store and shift the elemnet
                // cache.erase(begin(cache)+i);// automatically shifts to the left side as deleting the element 
           //     cache.push_back(temp);
           //     return val;
        //    }
     //   }
     //   return -1;
  //  }
    
    // void put(int key, int value) {
    //     int n=cache.size();
    //     for(int i{0};i<n;i++){
    //         if(cache[i].first==key){
    //             cache[i].second=value;
    //             pii temp=cache[i];
    //             cache.erase(begin(cache)+i);
    //             cache.push_back(temp);
    //             return;
    //         }
    //     }
    //     if(n==capacity){
     //       cache.erase(begin(cache));// if the capacity is full
      //  }
    //    cache.push_back({key,value});// if not
 //   }
//   };

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
