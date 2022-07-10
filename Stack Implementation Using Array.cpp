// Stack class.
class Stack {
    public:
        int size;
        int *arr;
        int topp;
    
public:
    
    Stack(int size) {
        this-> size = size;
        arr = new int[size];
        topp = -1;
    }

  
  // Pushing the elements in the stack
    void push(int element) {
        if (size - topp > 1)
            topp++;
            arr[topp] = element;
    }

  // Pop operation
  
    int pop() {
        if (topp >= 0){
            return arr[topp--];
        }
        else
            return -1;
    }
    
  
  // Return the top element
    int top() {
        if (topp >= 0 && topp < size){
            return arr[topp];
        }
        else
            return -1;
    }
    
  
  // Returns the given stack is empty or not
    int isEmpty() {
        if (topp == -1){
            return 1;
        }
        else
            return 0;
    }
    
  
  // Returns the stack is full or not
    int isFull() {
        if (topp >= size -1){
            return 1;
        }
        else 
            return 0;
    }
    
};


// All the operation performed in O(1) -> Time Complexity


