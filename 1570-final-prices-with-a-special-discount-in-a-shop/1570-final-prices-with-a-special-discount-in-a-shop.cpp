class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        int n = prices.size(); 
        vector<int> ans(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            if (!s.empty()) {
                if (s.top() <= prices[i])
                    ans[i] = s.top();
                else {
                    while (!s.empty() && (s.top() > prices[i]))
                        s.pop();
                    if (!s.empty())
                        ans[i] = s.top();
                }
            }
            s.push(prices[i]);
        }

        vector<int> sp(n);
        for (int i = 0; i < n; i++)
            sp[i] = prices[i] - ans[i];
        return sp;
    }
};