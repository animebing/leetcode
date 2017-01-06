// use another stack in push operation so that the elements in stack is in right order
// this is time consuming if the push operation is frequent
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        stack<int> tmp;
        while (!s.empty()){
            tmp.push(s.top());
            s.pop();
        }
        s.push(x);
        while (!tmp.empty()){
            s.push(tmp.top());
            tmp.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        s.pop();  
    }

    // Get the front element.
    int peek(void) {
        return s.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }
private:
    stack<int> s;
};

// based on the solution of StefanPochmann
// use two stacks input and output, input for push new elements, the order is inverse
// output for pop/peek elements, the order is right
// when output is empty, move all elements in input to output
// this method is not time consuming if the push operation is frequent
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        input.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        peek();
        output.pop();
    }

    // Get the front element.
    int peek(void) {
        if (output.empty()){
            while (!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return input.empty() && output.empty();
    }
private:
    stack<int> input, output;
};