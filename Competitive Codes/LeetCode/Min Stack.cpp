class MinStack {
    stack< pair<int,int>> s;
public:
    MinStack() {
        
    }
    
    void push(int x) {
        if(s.empty()) s.push(make_pair(x,x));
        else{
            int maxa = min(x,s.top().second);
            s.push(make_pair(x,maxa));
        }
    }
    
    void pop() {
      //  if(!s.empty())
        s.pop();
    }
    
    int top() {
        //if(!s.empty())
        return s.top().first;
    }
    
    int getMin() {
        //if(!s.empty()){
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */