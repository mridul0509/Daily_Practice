class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> result;
        set<int> allPlayers;
        set<int> losers;
        vector<int> notLost;
        vector<int> oneLost;
        map<int,int> lostCount;
        for(auto i: matches){
            allPlayers.insert(i[0]);
            allPlayers.insert(i[1]);
            losers.insert(i[1]);
            lostCount[i[1]]++;
        }
        for(auto i : allPlayers){
            if(losers.find(i) == losers.end()){
                notLost.push_back(i);
            }
        }
        for(auto i:lostCount){
            if(i.second == 1)
                oneLost.push_back(i.first);
        }
        result.push_back(notLost);
        result.push_back(oneLost);
        return result;
    }
};
