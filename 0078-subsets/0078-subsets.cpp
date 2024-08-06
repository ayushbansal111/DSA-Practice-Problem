class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int st = 0; st < (1 << nums.size()); st++) {
            ans.push_back({});
            for(int i = 0; i < nums.size(); i++) {
                if(st & (1 << i)) {
                    ans.back().push_back(nums[i]);
                }
            }
        }
        return ans;
    }
};