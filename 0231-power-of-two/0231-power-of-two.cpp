class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        return ((1<<30) % n == 0)? true:false;
    }
};