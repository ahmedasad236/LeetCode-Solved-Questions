class Solution {
public:
    int stringToDecimal(string s) {
        int sum = 0;
        int ten = 1;
        for(int i = s.size() - 1; i >= 0; i--) {
            sum += ten * (s[i] - '0');
            ten *= 10;
        }
        return sum;
    }
    
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
    
    string solveRecursive(string s, int& index) {
        string res = "";
        int n = s.size();
        while(index < n && s[index] != ']') {
            if(!isDigit(s[index]))
                res += s[index++];
            else {
                int num = 0;
                while(index < n && isDigit(s[index])) {
                    num = num * 10 + (s[index++] - '0');
                }
                index++; // skip [
                string temp = solveRecursive(s, index);
                index++; // skip ]
                for(int i = 0; i < num; i++) res += temp;
            }
                
        }
        
        return res;
    }
    
    string decodeString(string s) {
        int index = 0;
        return solveRecursive(s, index);
    }
};