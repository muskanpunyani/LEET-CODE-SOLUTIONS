An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

Example 1:

Input: low = 100, high = 300
Output: [123,234]

Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]

 

Constraints:

    10 <= low <= high <= 10^9


***********************************************************************************************************************************
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
    /* we know that the sequential digits wil be till 10^9
    i.e 12,123,1234,12345,123456,12345678,123456789,23,234,235........etc;
    therefore, we will generate all the possible seqential digits in the range 10< <10^9
    and then we will compare them with high and low and insert them if it is in range
     */
        
        for(int i=1;i<9;i++)  // from 1 because range is from 10
        {
            int number=i;
            for(int j=i+1;j<10;j++)   // generating every sequential no through these loops
            {
                number=number*10 + j;
                if(number>=low && number<=high)
                {
                    ans.push_back(number);
                }
            }
        }
        sort(ans.begin(),ans.end()); // output should be sorted(given in que)
        return ans;
        
    }
};
