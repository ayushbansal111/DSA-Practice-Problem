class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxSeq = 0;

        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int currNum = num;
                int currSeq = 1;
                while (numSet.find(currNum + 1) != numSet.end()) {
                    currNum++;
                    currSeq++;
                }
                maxSeq = max(maxSeq, currSeq);
            }
        }
        return maxSeq;
    }
};