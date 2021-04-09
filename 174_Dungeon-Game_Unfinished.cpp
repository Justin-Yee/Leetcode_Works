#include <stdio.h>
// #include <iostream>
// #include <string>
#include <vector>

using namespace std;

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
    }

int main()
{
    /*
    
    depth first? - find pos / zero solutions first to cut loading times; 
        -the first pos / 0 path will always be the lowest?
            -counter, mass negative first (-200) b4 all pos path (1) cost more than full neg path (-1)

    breath first - but you can abandon a path for another if theres a massive spike in hp needed

        -if two paths meet at the same tile; you can yeet out one thread as they both meet the same requirement?
        - i like the idea of breath first but i have no idea how to implement as a dynamic programming 

    
    -upfront high negative cost should always be avoided
            -even if there was a good path behind it; the upfront hp cost will eleminate it as a good option
    -pos paths arnt the best unless its a full path to and from start exit
        -unknown if its cheaper to follow a drastic differing cheap path
    -the best path between x and y will still be best path between x and z if x and y are sub paths
        -problem; the need to connect the subpaths
    -if two searches meet at the same tile; the one with the best answer will always win; meaning the other path can be destroyed
    -it is require to search through ALL nodes for a path to ensure success

    obj pathing{
        highest hp needed: //when exceeds curr hp; add to this
        curr hp: //whenver healled; add here; else go to highest
        path taken: //recording path is important but costly
            - can be cut with same tile theorem + sub route theorem
            - not needed if we use a global board tracker

    }

    global vector[m][n] board tracker;
        //holds lowest sum of hp to get to x location
        //when calculating; you can write on the board; if that location has been written then
            if you are higher or equal; you lost, end process
            if you are lower; you win, continue
        //? whole board starts off at -1; all pos # is max hp needed to get to x location


    step 1: int whole board as global
    step 2: start at corner and start recursive function
    step 3: write to board
    step 4: repeat till end
    step 5: max hp needed will be in lower right; just follow track backwards
        -best answer will naturally come out of that

        recursive(coords curr){
            
            if(board[curr] > 0){ //if hurt
                if(currHp+board[curr] < 0){//hp goes to neg
                    currHp = 0;
                    totHp -= board[curr]+currHp (turns it pos)
                }
                else{
                    currHp += board[curr]
                }
            }
            else{ //else heal
                currHp += board[curr]
            }

            //write to board
            curr


            if(curr.next != m)
                recursive(right coords)
            if(curr.next != n)
                recursive(down coords)
        }





    */

    printf("Hello World \n");

    vector<vector<int>> dungeon = {
        {1,1,1},
        {1,1,1},
        {1,1,1}};

    dungeon = {
        {0, 1, -3},
        {-1,-2, 0},
        {0, 0,  0}};


    return 0;
}
