Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:

Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.

Example 2:

Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.

Example 3:

Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.

*********************************************************************************************************************


class Solution {
public:
    int thirdMax(vector<int>& nums) {
       int n=nums.size();
        long long first=nums[0],second=LLONG_MIN,third=LLONG_MIN;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==first || nums[i]==second || nums[i]==third)  // if the element is equal to any of 1st 2nd or third skip it
            {
                continue;
            }
            if(nums[i]>first)
            {
               third=second;
                second=first;
                first=nums[i];
              }
            else if(nums[i]>second)
            {
               
                third=second;
                second=nums[i];
               
                
            }
            else if(nums[i]>third)
            {
                third=nums[i];
            }
        }
        return third==LLONG_MIN ? first: third; // if 3rd max not found return 1st max
        
        }
};
