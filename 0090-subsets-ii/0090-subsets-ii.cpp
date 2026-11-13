class Solution {
public:
    void uniqueSubsets(int i , int N , vector<int> &nums , vector<int> &curr , set<vector<int>> &s){
        if(i == N){
            s.insert(curr);
            return;
        }

        curr.push_back(nums[i]);
        uniqueSubsets(i+1 , N , nums , curr , s);
        curr.pop_back();
        uniqueSubsets(i+1 , N , nums , curr , s);

        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        set<vector<int>> s;
        int N = nums.size();

        sort(nums.begin() , nums.end());
        uniqueSubsets(0 , N , nums , curr , s);

        for(const vector<int> &subset : s){
            res.push_back(subset);
        }

        return res;
    }
};