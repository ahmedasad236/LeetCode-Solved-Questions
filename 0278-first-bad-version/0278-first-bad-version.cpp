// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 1, r = n;
        long long bad = (long long)n + 1;
        while(l <= r) {
            long long mid = l + (r - l) / 2;
            if(isBadVersion(mid))
                bad = min(bad, mid), r = mid - 1;
            else l = mid + 1;
        }
        return bad;
    }
};