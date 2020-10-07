// problem - https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        // assume 
        // input = [1,2,3,4]
        // ans = [1,1,1,1]
        int product = 1;
        
        
        // after this pass the answer becomes
        // ans = [1, 1, 2, 6]
        for(int i=0; i<nums.size()-1; ++i) {
            product *= nums[i];
            ans[i+1] = product;
        }

        product = 1;
        for(int i=nums.size()-1; i>0; i--) {
            product *= nums[i];
            ans[i-1] *= product;
        }
        return ans;
    }
};
