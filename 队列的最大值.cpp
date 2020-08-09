class MaxQueue {
    queue<int> x_queue;
    deque<int> max_queue;
public:
    MaxQueue() {
    }
    
    int max_value() {
        if (max_queue.empty())
            return -1;
        return max_queue.front();
    }
    
    void push_back(int value) {
        while (!max_queue.empty() && max_queue.back() < value) {
            max_queue.pop_back();
        }
        max_queue.push_back(value);
        x_queue.push(value);
    }
    
    int pop_front() {
        if (x_queue.empty())
            return -1;
        int ans = x_queue.front();
        if (ans == max_queue.front()) {
            max_queue.pop_front();
        }
        x_queue.pop();
        return ans;
    }
};


/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
