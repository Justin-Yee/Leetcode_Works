#include <stdio.h>
#include <iostream>
#include <string>
// #include <vector>

using namespace std;

bool compare_size(int i, int j){
    if(i < j)
        return 1;
    else
        return 0;
}

string alphabetBoardPath(string target) {
    int curr_x = 0, curr_y = 0, next_x, next_y;
    bool up_down, left_right;
    char *it1 = new char();
    it1 = &target[0];

    string ans = "";
    for(int i = 0; i < target.length();i++){
        int j = (*(it1+i)-97);   
        
        if(j <= 4){
            next_x =j;
            next_y =0;
            left_right = compare_size(curr_x,next_x);
            up_down = compare_size(curr_y,next_y);
        }
        else if(j <= 9){
            next_x =j - 5;
            next_y =1;
            left_right = compare_size(curr_x,next_x);
            up_down = compare_size(curr_y,next_y);
        }
        else if(j <= 14){
            next_x =j - 10;
            next_y =2;
            left_right = compare_size(curr_x,next_x);
            up_down = compare_size(curr_y,next_y);
        }
        else if(j <= 19){
            next_x =j - 15;
            next_y =3;
            left_right = compare_size(curr_x,next_x);
            up_down = compare_size(curr_y,next_y);
        }
        else if(j <= 24){
            next_x =j - 20;
            next_y =4;
            left_right = compare_size(curr_x,next_x);
            up_down = compare_size(curr_y,next_y);
        }
        else if(j == 25){
            next_x =j - 25;
            next_y =5;
            left_right = compare_size(curr_x,next_x);
            up_down = compare_size(curr_y,next_y);
        }
        else if(j > 25){
            cout << j << "\n";
            return "count error";
        }
        // cout <<"\n i: " << i << " j: " << j << " prev_ans: " << ans;
        // cout <<"\nn_x: " << next_x <<" n_y: "<< next_y;
        // cout <<"\nlr: " << left_right << " ud: " << up_down;
        // cout <<"\nc_x: " << curr_x << " c_y: " << curr_y << "\n";

        while(curr_x != next_x){
            if(curr_y == 5){
                curr_y--;
                string temp2 = "U";
                ans.insert(ans.length(),temp2);
            }

            if(left_right){
                curr_x++;
                //add to ans
                string temp2 = "R";
                ans.insert(ans.length(),temp2);
            }
            else{
                curr_x--;
                string temp2 = "L";
                ans.insert(ans.length(),temp2);
            }

            if(curr_x > 10 || curr_x < -10){
                cout << curr_x << "\n";
                return "left right error";
            }
        }

        while(curr_y != next_y){
            if(up_down){
                curr_y++;
                //add to ans
                string temp2 = "D";
                ans.insert(ans.length(),temp2);
            }
            else{
                curr_y--;
                string temp2 = "U";
                ans.insert(ans.length(),temp2);
            }


            if(curr_y > 10 || curr_y < -10){
                cout << curr_y << "\n";
                return "up down error";
            }
        }

        // string temp2 = "!";
        // ans.insert(0,temp2);
        ans.append(1,33);

    }

    return ans;
}

int main()
{
    /*

    curr_x, curr_y start at A;
    next_x, next_y is Target Letter
    bool up_down, left_right;

    string answer;

    for(length of target String){

        -find target: set next_x,next_y, and bools
            -case 1: target is away from me
            -case 2: im already at target
            -case 3: invalid target
        
        {0,1,2,3,4}
        {5,6,7,8,9}
        {10,11,12,13,14}
        {15,16,17,18,19}
        {20,21,22,23,24}
        {25}
        case: i <= 5
            next_y = 0
            next_x = char - 48

        case: i <= 10
            next_y = 1
            next_x = char - 48 - 5
        ....
        case: i <= 15
            next_y = 2
            next_x = char - 48 - 10
        case: i == 26
            next_y = 5
            next_x = char - 48 - 25

        -write to answer
        while(next_y != curr_y){
            if(up_down){//Going up
                write(U)
                next_x++;
            }
            else{
                write(D)
                next_x--;
            }
        }

        while(next_x != curr_x){
            if(left_right){//Going up
                write(L)
                next_x++;
            }
            else{
                write(R)
                next_x--;
            }
        }
        //same for up down

        write(!)//we at target
    }
    return answer;

    */
    printf("Hello World \n");
    string temp = alphabetBoardPath("a");
    // printf("! ==  ");
    // cout << temp << "\n";
    
    temp = alphabetBoardPath("zdz");
    printf("DDDDD!UUUUURRR!DDDDLLLD! == ");
    cout << temp << "\n";

    // temp =  alphabetBoardPath("code");
    // printf("RR!DDRR!UUL!R! == ");
    // cout << temp << "\n";

    return 0;
}
