#include <vector>
using namespace std;

class MyStack {
private:
    vector<int> stack; 

public:
    MyStack() {
        
    }
    
    void push(int x) {
        stack.push_back(x); 
    }
    
    int pop() {
        int topElement = stack.back(); 
        stack.pop_back(); 
        return topElement;
    }
    
    int top() {
        return stack.back(); 
    }
    
    bool empty() {
        return stack.empty(); // Check if  empty
    }
};
