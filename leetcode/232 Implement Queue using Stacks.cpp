
class Queue {

public:

    stack<int> in;
    stack<int> out;
    // Push element x to the back of queue.
    void push(int x) {
        in.push(x);
    }
    // Removes the element from in front of queue.
    void pop(void) {
        for(;!in.empty();){
            out.push(in.top());
            in.pop();
        }
        out.pop();
        for(;!out.empty();){
            in.push(out.top());
            out.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        for(;!in.empty();){
            out.push(in.top());
            in.pop();
        }
        int t = out.top();
        for(;!out.empty();){
            in.push(out.top());
            out.pop();
        }
        return t;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return in.empty();
    }
};