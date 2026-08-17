class Solution {
public:
    int solve(int l,int r,vector<int> &cumSum,vector<vector<int>>& dp){
       
        int score = 0;
         if (l == r)
            return dp[l][r]= 0;
         if(dp[l][r]!=-1)return dp[l][r];
        for(int mid=l;mid<=r;mid++){
           int leftSum = cumSum[mid] - (l > 0 ? cumSum[l-1] : 0);
            int rightSum = cumSum[r] - cumSum[mid];
            if(leftSum<rightSum)
            score = max(score,leftSum+solve(l,mid,cumSum,dp));
            else if(rightSum<leftSum)
            score = max(score,rightSum+solve(mid+1,r,cumSum,dp));
            else score = max({
                    score,
                    leftSum + solve(l, mid, cumSum,dp),
                    rightSum + solve(mid + 1, r, cumSum,dp)
                });


        }
    return dp[l][r]=score;
    }
    int stoneGameV(vector<int>& stoneValue) {
       vector<vector<int>> dp(stoneValue.size()+1, vector<int>(stoneValue.size()+1, -1));
        vector<int> cumSum(stoneValue.size(),0);
        cumSum[0] = stoneValue[0];
        for(int i=1;i<stoneValue.size();i++)cumSum[i] = cumSum[i-1] + stoneValue[i];
        return solve(0,stoneValue.size()-1,cumSum,dp);
    }
};