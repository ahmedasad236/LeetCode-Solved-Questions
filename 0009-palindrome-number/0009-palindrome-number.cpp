class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        vector<int> digits;
        while(x) {
            digits.push_back(x%10);
            x /= 10;
        }
        for(int i = 0, n = digits.size(); i < n / 2; i++) {
            if(digits[i] != digits[n - i - 1]) return false;
        }
        return true;
    }
};