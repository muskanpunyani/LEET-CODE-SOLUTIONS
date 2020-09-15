

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:

Input: "Hello World"
Output: 5

*********************************************************************************************
class Solution {
public:
    int lengthOfLastWord(string s) {
      int flag=0;    // take flag
     stringstream s1(s);    // string stream declaration
        string word;
        string result;
        while(s1>>word)    
        {
            result=word;    // store the word in result, every time the result will be replaced by new word
                            // and finally the last word will be stored in result
            flag=1;
        }
        if(flag==0)
        {
            return 0;
        }
        return result.length();  // returning length of last word
    }
};
