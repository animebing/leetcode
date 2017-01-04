// based on the solutio of sjtuldk 
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        elements.push(x);   
        for (int i = 0; i < elements.size()-1; i++){
            elements.push(elements.front());   // rotate the queue to make it alike stack
            elements.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        elements.pop();
    }

    // Get the top element.
    int top() {
        return elements.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return elements.empty();
    }
private:
    queue<int> elements;
};