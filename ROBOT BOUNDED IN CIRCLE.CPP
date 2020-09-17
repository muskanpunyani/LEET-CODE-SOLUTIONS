On an infinite plane, a robot initially stands at (0, 0) and faces north.  The robot can receive one of three instructions:

    "G": go straight 1 unit;
    "L": turn 90 degrees to the left;
    "R": turn 90 degress to the right.

The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

 

Example 1:

Input: "GGLLGG"
Output: true
Explanation: 
The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.

Example 2:

Input: "GG"
Output: false
Explanation: 
The robot moves north indefinitely.

Example 3:

Input: "GL"
Output: true
Explanation: 
The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...

 

Note:

    1 <= instructions.length <= 100
    instructions[i] is in {'G', 'L', 'R'}

   ************************************************************************8
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0;
        int y=0;
        int north=true;  // initially we are going in north
        int south=false;
        int east=false;
        int west=false;
        int n=instructions.length();
        for(int i=0;i<n;i++)
        {
            if(instructions[i]=='G')
            {
                if(north)
                y++;
               else if(west)
                    x--;
                else if(east)
                    x++;
                else if(south)
                    y--;
            }
            else if(instructions[i]=='L')   // anticlockwise
            {
                if(north) // i.e the point was in north dirn
                {
                    north=false;
                    west=true;   // left of north is west
                }
                else if(west) 
                {
                    south=true;     // left of west
                    west=false;  
                }
                 else if(south) 
                {
                    south=false;
                    east=true;     // left of south
                }
                  else if(east) 
                {
                    north=true;   // left of east
                    east=false;  
                }
            }
            else if(instructions[i]=='R')  // clockwise
            {
               if(north)
               {
                   north=false;
                   east=true;   // right of north
               }
                else if(east)
                {
                    east=false;
                    south=true;
                }
                else if(south)
                {
                    south=false;
                    west=true;
                }
                else if(west)
                {
                    west=false;
                    north=true;
                }
            }
        }
        if(!north || (x==0 && y==0 ))  // if the dirn is not north or we are back to origin
        {
            return true;
        }
        return false;
        
    }
};
