class Solution {
public:
    int countOdds(int low, int high) {
        long long range = high - low + 1;
        if(range & 1)  {
            range--;
            return (range / 2 + (high & 1 ? 1 : 0));
        } else {
            return range / 2;
        }
    }
};