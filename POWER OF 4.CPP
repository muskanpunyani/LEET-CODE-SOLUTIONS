/***
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true

Example 2:

Input: 5
Output: false

Follow up: Could you solve it without loops/recursion?
***/

class Solution {
public:
    float answer(int num)
    {
       
        return (log(num)/log(4));   // log (number)/log(base)=log(base)(number)
    }
    bool isPowerOfFour(int num) {
        if(num==0)
        {
            return false;
        }
        return (floor(answer(num))==ceil(answer(num)));  // if floor and ceil val is same it means the log is integer and thus power of e4 as we have taken base 4
       
        }
};
