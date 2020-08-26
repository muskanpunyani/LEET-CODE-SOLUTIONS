
/*********Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
****/



class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(to_string(i+1));
        }
        for(int i=2;i<n;i+=3)
        {
            ans[i]="Fizz";
        }
        for(int i=4;i<n;i+=5)
        {
            if(ans[i]=="Fizz")
            {
                ans[i]=ans[i]+"Buzz";
            }
            else{
                ans[i]="Buzz";
            }
        }
        return ans;
        
    }
};
