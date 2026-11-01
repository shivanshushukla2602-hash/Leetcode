class FreqStack {
public:
    unordered_map<int , stack<int>> fs;
    unordered_map<int , int> um;

    FreqStack() {
        
    }
    
    void push(int val) {
        um[val]++;
        int freq = um[val];
        
        if(fs.find(freq) == fs.end()){
            stack<int> st;
            fs[freq] = st;
        }
        fs[freq].push(val);
    }
    
    int pop() {
        int freq = fs.size();
        int elem = fs[freq].top();
        fs[freq].pop();

        if(fs[freq].size() == 0){
            fs.erase(freq);
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