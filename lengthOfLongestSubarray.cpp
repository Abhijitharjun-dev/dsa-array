class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0,j=0;
        int n = nums.size();
        int result= 0;
        int culprit=0;
        unordered_map<int,int>mpp;
        while(j<n){
          mpp[nums[j]]++;
          if(mpp[nums[j]]==k+1)culprit++;
          if(culprit>0){
            mpp[nums[i]]--;
            if(mpp[nums[i]]==k)culprit--;

        i++;
         
          }
        if(culprit==0)result=max(result,j-i+1);
        j++;
        }
     return result;
    }
};