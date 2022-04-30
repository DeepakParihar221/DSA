class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int gassum = 0, costsum = 0;
        for(int i=0;i<n;i++){
            gassum += gas[i];
            costsum += cost[i];
        }
        
        if(gassum<costsum)
            return -1;
        
        int tank = 0;
        int index = 0;
        for(int i=0;i<n;i++){
            tank += gas[i]-cost[i];
            if(tank<0){
                tank = 0;
                index = i+1;
            }
        }
        return index;
    }
};