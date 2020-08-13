/****
Design an Iterator class, which has:

    A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
    A function next() that returns the next combination of length combinationLength in lexicographical order.
    A function hasNext() that returns True if and only if there exists a next combination.

 

Example:

CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false

 

Constraints:

    1 <= combinationLength <= characters.length <= 15
    There will be at most 10^4 function calls per test.
    It's guaranteed that all calls of the function next are valid.

Hint #1  
Generate all combinations as a preprocessing.

 Hint #2  
Use bit masking to generate all the combinations.

*****/

class CombinationIterator {
public:
    vector<string> ans;
    CombinationIterator(string characters, int combinationLength) {
        int l=characters.length(); 
        vector<vector<string>> res1;
        int pow_no=pow(2,l);  
        int counter,j;
        for(counter=0;counter<pow_no;counter++)
        {
            vector<string> v1;
            for(int j=0;j<l;j++)
            {
                if(counter & (1<<j)) //check the bit which is set
                {
                    string s =string(1,characters[j]);
                    v1.push_back(s);
                }
               
               
            }
           
             res1.push_back(v1);
           
             
        }
        // now everhy possible subset is stored
        // we will find every subset of given length
        
        for(int i=0;i<res1.size();i++)
        {
             string s1="";
            if(res1[i].size()==combinationLength)
            {
               
                for(int m=0;m<res1[i].size();m++)
                {
                    string s2=res1[i][m];
                    s1= s1+ s2;
                }
                
            ans.push_back(s1);  //vector of strings with given size
               
            }
        }
         sort(ans.begin(),ans.end());  // sorting because we wantoutput in lexicographical order
                
        
        
        
    }
    
    string next() {
       string n1=ans.front();
        ans.erase(ans.begin());
        return n1;
        
        
        
        
    }
    
    bool hasNext() {
        if(ans.empty()==false)
        {
            return true;
        }
        else{
            return false;
        }
        
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
