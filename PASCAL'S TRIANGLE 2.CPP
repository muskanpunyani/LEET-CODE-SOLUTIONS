/*****
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]

Follow up:

Could you optimize your algorithm to use only O(k) extra space?

****/



class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result; 
        result.push_back(1); // first case
        if(rowIndex==0)
        {
            return result;
        }
        result.push_back(1); // 2nd case
        if(rowIndex==1)
        {
            return result;
        }
        for(int i=2;i<=rowIndex;i++)
        {
            vector<int> temp; //temp vector to store result of that part
            temp.push_back(1); //border
            for(int j=0;j<result.size()-1;j++) // the new elements except corner will be the size of older elements array-1
            {
                temp.push_back(result[j]+result[j+1]);
            }
            temp.push_back(1);  //corner
            result=temp;
            
        }
        return result;
        
    }
};
