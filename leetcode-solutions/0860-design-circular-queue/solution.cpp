class Node{
  public://constructor should be public
    int val;
    Node* next;
    
    Node(int val){
        this->val=val;
        this->next=nullptr;
    }
};
class MyCircularQueue {
    private:
    int currsize,cap;
    Node *front,*rear;
public:

    MyCircularQueue(int k) {
      this->cap=k;
      currsize=0;
      front =NULL;
      rear=NULL;

    }
    
    bool enQueue(int value) {
        if(isFull())
        return false;
         Node* newNode=new Node(value);
        if(isEmpty()){
            // Node* newNode=new Node(value);
            front= newNode;
            rear=newNode;
            // currsize++;
            // return true;
        }
        else{
            // rear->next=new Node(value); avoiding repitation
            rear->next=newNode;
            rear=rear->next;
            // currsize++;
            // return true;
        }
             currsize++;
            return true;
    }
    
    bool deQueue() {
        if(isEmpty())
        return false;

        Node* temp=front;

        if(currsize==1){
            front=nullptr;
            rear=nullptr;
        
        }
        else{
            front=front->next;

        } 
        currsize--;
        delete temp;
        return true;
    }
    
    int Front() {
        return isEmpty()?-1:front->val; 
    }
    
    int Rear() {
        return isEmpty()?-1:rear->val;
    }
    
    bool isEmpty() {
        return currsize==0;
    }
    
    bool isFull() {
        return currsize==cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
