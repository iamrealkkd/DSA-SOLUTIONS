class Solution {
public:

    int solve(int i, vector<int>& nums, vector<int>& dp){

        if(i==0)
            return nums[0];

        if(dp[i]!=INT_MIN)
            return dp[i];

        return dp[i]=max(

            nums[i],

            nums[i]+solve(i-1,nums,dp)

        );
    }

    int maxSubArray(vector<int>& nums) {

        int n=nums.size();

        vector<int> dp(n,INT_MIN);

        int ans=INT_MIN;

        for(int i=0;i<n;i++){

            ans=max(ans,solve(i,nums,dp));

        }

        return ans;
    }
};