// *************************************** Implementation of Queue using Array ****************************************************


class Queue {
    int *arr;
    int qfront;
    int rear;
    int size;
    
public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if ( qfront == rear)
            return true;
        else
            return false;
    }

    void enqueue(int data) {
        if(qfront == size )
            return ;
        else{
            arr[rear] = data;
            rear++;
            
        }
    }

    int dequeue() {
        if (qfront == rear)
            return -1;
       
        else
        {
            int ans = arr[qfront];
            qfront++;
            if (qfront == rear){
                qfront = rear = 0;
            }
            return ans;
        }
        
    }

    int front() {
        
        if(qfront == rear)
            return -1;
        else 
        {
            return arr[qfront];
        }
        
    }
};


