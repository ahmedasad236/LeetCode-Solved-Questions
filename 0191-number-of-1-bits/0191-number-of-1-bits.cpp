class Solution {
public:
    int hammingWeight(uint32_t n) {
        // O(number of set bits)
        int cnt = 0;
        while(n) {
            cnt++;
            n = n & (n - 1); // removes the right most set bit
            // if n = 9 = 1001, then n - 1 = 8 = 1000, then n & (n - 1) = 1000
        }
        return cnt;
    }
};