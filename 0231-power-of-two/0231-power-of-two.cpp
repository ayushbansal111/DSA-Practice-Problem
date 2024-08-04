class Solution {
public:
    bool isPowerOfTwo(int n) {
        int mask = 1;
        while (mask <= n) {
            if (mask == n)
                return true;
            if (mask > INT_MAX / 2)
                break;
            mask = mask << 1;
        }
        return false;
    }
};