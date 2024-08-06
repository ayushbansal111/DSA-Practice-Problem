class Solution {
public:
    void print(vector<int>& nums, int i, int n, vector<int>& result,
               vector<vector<int>>& ans) {

        if (i == n) {
            ans.push_back(result);
            return;
        }

        result.push_back(nums[i]);
        print(nums, i + 1, n, result, ans);

        result.pop_back();
        print(nums, i + 1, n, result, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> result;

        print(nums, 0, nums.size(), result, ans);
        return ans;
    }
};