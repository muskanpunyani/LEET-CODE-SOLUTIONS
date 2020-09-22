Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]

Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]


**********************************************************************************************************************************************
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // we can think that dividing any N by 3, the remainder wil be either 1 or 2, i.e at max 2 elemnts will have greater than n/3 occurence
        // thus we will take two variables val1,val2 for storing these 2 integers
        // count1 and count2 will store the no of occurence
        
        int l=nums.size();
        int val1=0,val2=0;
        int count1=0,count2=0;
        vector<int> ans;
        if(l==0)
        {
            return ans;
        }
        if(l==1) // if size is 1,n/3=0 ,i.e every element will be pushed
        {
            ans.push_back(nums[0]);
            return ans;
        }
       if(l==2)  // if size is 2 , i.e every unique element will be pushed
        {
           int v1=nums[0];
           int v2=nums[1];
           if(v1!=v2)
           {
            ans.push_back(nums[0]);
            ans.push_back(nums[1]);
           }
           else{
               ans.push_back(v1);
           }
            return ans;
        }
        
        for(int i=0;i<l;i++)
        {
            if( val1==nums[i])  // if val1 is repeating,increment count1
            {
                val1=nums[i];
                count1++;
            }
            else if( val2==nums[i])  // if val2 is repeating increment,count2
            {
                val2=nums[i];
                count2++;
            }
            else if(count1==0)   // if count1 or count2 is 0,restart
            {
                val1=nums[i];
                count1=1;
            }
            else if(count2==0)
            {
                val2=nums[i];
                count2=1;
            }
            else{                // if nums[i] is neither val1 nor val2 both count will be decreased
                count1--;
                count2--;
            }
        }
        //now we will check whether the 2 values(val1 and val2) are occuring more than n/3 times (confirmation) 
        count1=0,count2=0;
        for(int i=0;i<l;i++)
        {
            if( nums[i]==val1)
            {
                count1++;
            }
            else if( nums[i]==val2)
            {
                count2++;
            }
        }
        if(count1>floor(l/3))
        {
            ans.push_back(val1);
        }
        if(count2> floor(l/3))
        {
            ans.push_back(val2);
        }
        return ans;
    }
};
