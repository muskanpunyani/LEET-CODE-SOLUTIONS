/****Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
****/

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m; // map to store frequency of every character
        int l=s.length();
        for(auto i=0;i<l;i++)
        {
            m[s[i]]++;
        }
        int count1=0; // storing count of every character
        int odd_count=0 ; // storing count numbers whose freq is odd
        int answer;
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(((it->second) %2 ) != 0) // that is odd count
            {
                odd_count++;
            }
            count1+=(it->second);
        }
        if(odd_count >0)  // 1 odd can be taken in between herefore subtracting remaining
        {
            odd_count--;
        }
        answer=(count1-odd_count);  // subtracting odd no from total count only 1 count can be taken rest all subtracted
        
        return answer;
    }
};
