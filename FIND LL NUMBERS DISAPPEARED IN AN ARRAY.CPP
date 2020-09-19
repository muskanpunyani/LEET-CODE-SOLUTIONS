Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
**********************************************************************************************************************8
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)  // in the array make the index of elemnt as negative, i.e val at that index negative
        {
            int temp=abs(nums[i]);
            if(nums[temp-1]>0)      // temp-1 is taken bcz array is 0 indexed
            {
                nums[temp-1]=-nums[temp-1];
            }
        }
        for(int i=0;i<nums.size();i++)  // the index which is positive means,its value doesn't occur in the array thus they are missing add them to ans
        {
            if(nums[i]>0)
            {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
