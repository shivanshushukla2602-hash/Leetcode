class Solution {
public:
    bool canJump(vector<int>& nums) {
        priority_queue<int> pq;
        int n = nums.size();

        pq.push(nums[0]);
        int i = 0;

        while(pq.size() > 0){
            int max = pq.top();
            pq.pop();

            if(max >= n-1){
                return true;
            }

            while(i <= max){
                pq.push(nums[i] + i);
                i++;
            }
        }

        return false;
    }
};