Given a list of intervals, remove all intervals that are covered by another interval in the list.

Interval [a,b) is covered by interval [c,d) if and only if c <= a and b <= d.

After doing so, return the number of remaining intervals.

 

Example 1:

Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.

Example 2:

Input: intervals = [[1,4],[2,3]]
Output: 1

Example 3:

Input: intervals = [[0,10],[5,12]]
Output: 2

Example 4:

Input: intervals = [[3,10],[4,10],[5,11]]
Output: 2

Example 5:

Input: intervals = [[1,2],[1,4],[3,4]]
Output: 1

 

Constraints:

    1 <= intervals.length <= 1000
    intervals[i].length == 2
    0 <= intervals[i][0] < intervals[i][1] <= 10^5
    All the intervals are unique.
***********************************************************************************************************************************************************

class Solution {
    /* if interval completely lies inside another then we dont want to take it,
    e.g. 3,6 lies completely inside 2,8
    i.e start time need to be smaller
    end time need to be greater,if start time is equal
    */
public:
   bool static sorter(vector<int>& v1, vector<int>& v2){
   // sorting in increasing order of start time
        if(v1[0] == v2[0]) return v1[1] > v2[1];   // end time (greater to lower)
        return v1[0] < v2[0];                         // start time(lower to greater)
    }    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int removed = 0, curr = 0;
        sort(intervals.begin(), intervals.end(), sorter);
        for(int i = 0; i < n - 1; i++){
            if(intervals[curr][0] <= intervals[i + 1][0] and intervals[curr][1] >= intervals[i + 1][1]){
                removed++;
            }
            else{
                curr = i + 1;
            }
        }
        return n - removed;
    }
};
