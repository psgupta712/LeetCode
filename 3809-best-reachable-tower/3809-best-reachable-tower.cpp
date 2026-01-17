class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int c1 = center[0];
        int c2 = center[1];

        int maxQ = -1;
        int bestX = -1, bestY = -1;

        for(int i=0; i<towers.size(); i++){
            int x = towers[i][0];
            int y = towers[i][1];
            int q = towers[i][2];

            int distance = abs(x - c1) + abs(y - c2);

            if(distance <= radius){
                if(q > maxQ){
                    maxQ = q;
                    bestX = x;
                    bestY = y;
                }
                else if(q == maxQ){
                    if(x < bestX || x == bestX && y < bestY){
                        bestX = x;
                        bestY = y;
                    }
                }
            }
        }
        if(maxQ == -1){
            return {-1, -1};
        }
        return {bestX, bestY};
    }

};