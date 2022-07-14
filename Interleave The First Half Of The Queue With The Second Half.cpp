#include <queue>

void interLeaveQueue(queue < int > & q) {
    
    queue <int> temp;
    
    int size = q.size()/2;
    
      for (int i = 0; i < size; i++)
      {
          int val = q.front();
          temp.push(val);
          q.pop();
      }
    
        while (!temp.empty())
        {
            int val = temp.front();
            temp.pop();
            q.push(val);
            q.push(q.front());
            q.pop();
        }
    
    
}

