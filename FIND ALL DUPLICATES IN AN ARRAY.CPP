/****
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]

****/


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        if (n==0)
        {
            return ans;
        }
        for(int i=0;i<n;i++)
        {
          int ind=abs(nums[i])-1;    // taking index value as array value -1
            if(nums[ind]>=0)   // mark that index value visited
            {
                nums[ind]=-nums[ind];    
            }
            else{  // if the index is already visited push it 
                ans.push_back(ind+1);   // ind+1 because index was 1-original val,thus original val=+1 
            }
            
        }
        return ans;
        
    }
};
