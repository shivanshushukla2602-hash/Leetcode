class Solution {
public:
    int jump(vector<int>& nums) {
        priority_queue<int> pq;
        pq.push(nums[0]);

        int n = nums.size();
        int count = 0;
        int i = 0;

        if(n == 1){
            return 0;
        }

        while(pq.size() > 0){
            count++;

            int max = pq.top();
            pq.pop();

            if(max >= n-1){
                break;
            }

            while(max >= i){
                pq.push(nums[i] + i);
                i++;
            }
        }

        return count;
    }
};