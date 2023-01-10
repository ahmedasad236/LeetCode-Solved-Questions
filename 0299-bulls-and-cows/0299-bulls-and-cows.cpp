class Solution {
public:
    string convertToStr(int n) {
        if(!n) return "0";
        string s = "";
        while(n) {
            int mod = n % 10;
            s += (mod + '0');
            n /= 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    string getHint(string secret, string guess) {
        map<char, int> mp1, mp2;
        for(auto c : secret) mp1[c]++;
        //for(auto c : guess) mp2[c]++;
        int success = 0, failed = 0;
        for(int i = 0; i < secret.size(); i++) {
            if(secret[i] == guess[i]) {
                success++;
                mp1[secret[i]]--;
                //mp2[secret[i]]--;
                cout << "success " << secret[i] << '\n';
            } 
        } 
        for(int i = 0; i < secret.size(); i++) {
            if(secret[i] != guess[i] && mp1[guess[i]] > 0) {
                failed++;
                mp1[guess[i]]--;
                //mp2[secret[i]]--;
                cout << "failed " << secret[i] << '\n';
            } 
        }
        return convertToStr(success) + "A" + convertToStr(failed) + "B";
    }
};