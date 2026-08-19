class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>>mpp;
        for(auto &reserve:reservedSeats){
                 int row = reserve[0];
                 int col = reserve[1];
                 mpp[row].insert(col);
        }
        int result = (n - mpp.size())*2;
        for(auto&[key,val]:mpp){
            auto isAvailable = [&](int seat){
                return val.find(seat)==val.end();
            };
            bool groupA = isAvailable(2) && isAvailable(3) && isAvailable(4) && isAvailable(5);
            bool groupB = isAvailable(4) && isAvailable(5) && isAvailable(6) && isAvailable(7);
            bool groupC = isAvailable(6) && isAvailable(7) && isAvailable(8) && isAvailable(9);
            if(groupA && groupC)result+=2;
            else if(groupA || groupB || groupC) result+=1;
        }
    return result;
    }
};