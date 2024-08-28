class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int s = j + 1;
                int e = nums.size() - 1;
                long long currentTarget = (long long)target - nums[i] - nums[j];

                while (s < e) {
                    int sum = nums[s] + nums[e];
                    if (sum == currentTarget) {
                        ans.push_back({nums[i], nums[j], nums[s], nums[e]});
                        while (s < e && nums[s] == nums[s + 1])
                            s++;
                        while (s < e && nums[e] == nums[e - 1])
                            e--;
                        s++;
                        e--;
                    } else if (sum < currentTarget) {
                        s++;
                    } else {
                        e--;
                    }
                }
            }
        }
        return ans;
    }
};
