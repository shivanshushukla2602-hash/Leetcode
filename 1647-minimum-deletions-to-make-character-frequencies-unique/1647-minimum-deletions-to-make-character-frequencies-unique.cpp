class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char , int> um;
        for(int i = 0 ; i < s.size() ; ++i){
            um[s[i]]++;
        }

        int size1 = um.size();

        set<int> used;
        int deletions = 0;

        for(const auto &num : um){
            int freq = num.second;

            while(freq > 0 && used.count(freq)){
                --freq;
                ++deletions;
            }

            if(freq > 0){
                used.insert(freq);
            }
        }

        return deletions;
    }
};