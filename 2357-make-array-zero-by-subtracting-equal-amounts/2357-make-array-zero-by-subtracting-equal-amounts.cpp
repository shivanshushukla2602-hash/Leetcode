class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int , vector<int> , greater<int>> pq;

        int count = 0;
        while(true){
            for(int i = 0 ; i < nums.size() ; ++i){
                if(nums[i] != 0){
                   pq.push(nums[i]);
                }
            }

            if(pq.empty()){
                break;
            }

            int x = pq.top();

            for(int i = 0 ; i < nums.size() ; ++i){
                if(nums[i] != 0){
                   nums[i] -= x;
                }
            }

            while(pq.size() > 0){
                pq.pop();
            }

            count++;
        }

        return count;
    }
};