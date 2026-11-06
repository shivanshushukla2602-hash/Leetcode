class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> v;

        for(int i = 0 ; i < k ; ++i){
            while(dq.size() > 0 && dq.back() < nums[i]){
                dq.pop_back();
            }

            dq.push_back(nums[i]);
        }

        if(dq.size() > 0){
            v.push_back(dq.front());
        }

        int s = 1 , e = k;

        while(e < nums.size()){
            if(nums[s-1] == dq.front()){
                dq.pop_front();
            }

            while(dq.size() > 0 && dq.back() < nums[e]){
                dq.pop_back();
            }

            dq.push_back(nums[e]);

            if(dq.size() > 0){
                v.push_back(dq.front());
            }

            s++;
            e++;
        }

        return v;
    }
};