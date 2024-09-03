class Solution {
private:
    vector<int> getprev(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            // stack top is small
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> getnext(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            // stack top is small
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> prev;
        prev = getprev(heights, n);

        vector<int> next;
        next = getnext(heights, n);

        int area = 0;

        for (int i = 0; i < n; i++) {
            int l = heights[i];

            if (next[i] == -1)
                next[i] = n;

            int b = next[i] - prev[i] - 1;

            int newarea = l * b;
            area = max(area, newarea);
        }
        return area;
    }
};