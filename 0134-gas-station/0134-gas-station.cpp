class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumGas = 0, sumCost = 0;
        int start = 0;
        int currGas = 0;
        for(int i = 0; i < gas.size(); i++) {
            sumGas += gas[i];
            sumCost += cost[i]; 
            currGas += gas[i] - cost[i];
            if(currGas < 0) 
                start = i + 1, currGas = 0;
        } 
        return sumGas < sumCost ? -1 : start;
        
    }
};