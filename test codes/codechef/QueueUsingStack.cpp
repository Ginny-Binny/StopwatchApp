class MyQueue {
public:
    stack<int>in;
    stack<int>out;
    void push(int x) {
       in.push(x);
    }
    
    int pop() {
        //shift all elts from in to out
        while(out.empty())
        {
            while(in.size())
            {
                out.push(in.top());
                in.pop();
            }
        }
        int x=out.top();
        out.pop();
        return x;
    }
    
    int peek() {
     while(out.empty())
        {
            while(in.size())
            {
                out.push(in.top());
                in.pop();
            }
        }
       return out.top();
    }
    
    bool empty() {
        return out.empty() && in.empty();
    }
};
