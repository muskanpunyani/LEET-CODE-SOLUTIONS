/**Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

    All letters in this word are capitals, like "USA".
    All letters in this word are not capitals, like "leetcode".
    Only the first letter in this word is capital, like "Google".

Otherwise, we define that this word doesn't use capitals in a right way.

 

Example 1:

Input: "USA"
Output: True

 

Example 2:

Input: "FlaG"
Output: False

 

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/

class Solution {
public:
    bool allcapital(string word)
    {
        int l=word.length();
        for(int i=0;i<l;i++)
        {
            if(word[i]>='A' && word[i]<='Z')
            {
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
     bool allsmall(string word)
    {
        int l=word.length();
        for(int i=1;i<l;i++)  //this loop is from 1 because a[0] can be small or large
        {
            if(word[i]>='a' && word[i]<='z')
            {
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool detectCapitalUse(string word) {
        if(allcapital(word) || allsmall(word))
        {
            return true;
        }
        return false;
        
    }
};
