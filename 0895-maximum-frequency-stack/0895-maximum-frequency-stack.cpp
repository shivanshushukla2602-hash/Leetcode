class FreqStack {
public:
    unordered_map<int , stack<int>> fs;
    unordered_map<int , int> um;

    FreqStack() {
        
    }
    
    void push(int val) {
        um[val]++;
        int f = um[val];

        if(fs.find(f) == fs.end()){
            stack<int> s;
            fs[f] = s;
        }

        fs[f].push(val);
    }
    
    int pop() {
        int f = fs.size();
        int elem = fs[f].top();
        fs[f].pop();

        if(fs[f].size() == 0){
            fs.erase(f);
        }

        um[elem]--;
        return elem;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */