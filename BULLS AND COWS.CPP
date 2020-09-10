You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. 

Please note that both secret number and friend's guess may contain duplicate digits.

Example 1:

Input: secret = "1807", guess = "7810"

Output: "1A3B"

Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.

Example 2:

Input: secret = "1123", guess = "0111"

Output: "1A1B"

Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.

Note: You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.

*********************************************************************************************************************************************************************

class Solution {
public:
    string getHint(string secret, string guess) {
        int visited[100009];
        for(int i=0;i<100009;i++)
        {
            visited[i]=0;
        }
        int l1=secret.length();
        for(int i=0;i<l1;i++)
        {
            visited[secret[i]-'0']+=1;
        }
        int a=0,b=0;
        for(int i=0;i<l1;i++)
        {
            if(visited[guess[i]-'0'])
            {
               
                if(guess[i]==secret[i])  // for bull
                {
                    b++;
                    visited[guess[i]-'0']-=1;
                    
                }
              }
        }
        int total=0;
        map<char,int> m1,m2;
        for(int i=0;i<l1;i++)  // for storing secret
        {
            m1[secret[i]]++;
        }
        for(int i=0;i<l1;i++)  // for storing guess
        {
            m2[guess[i]]++;
        }
        /* now for cows we will find the total number of common elements and will subtract
        bull from that
        here b is bull
        a is cow
        */
       set<char> s;
        for(int i=0;i<l1;i++)
        {
            s.insert(secret[i]);
        }
        vector<int> v1;
        for(auto it=s.begin();it!=s.end();it++)
        {
            v1.push_back(*it);
        }
        for(int i=0;i<v1.size();i++)
        {
            total+=min(m1[v1[i]],m2[v1[i]]);
        }
        a=total-b;
        string ans=to_string(b)+"A"+to_string(a)+"B";
        return ans;
    }
};
