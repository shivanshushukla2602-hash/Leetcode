class Solution {
public:
    void allSubsets(int i , int n , vector<int> &nums , vector<int> &curr , vector<vector<int>> &res){
        if(i == n){
            res.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        allSubsets(i+1 , n , nums , curr , res);
        curr.pop_back();
        allSubsets(i+1 , n , nums , curr , res);

        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        int n = nums.size();

        allSubsets(0 , n , nums , curr , res);

        return res;
    }
};