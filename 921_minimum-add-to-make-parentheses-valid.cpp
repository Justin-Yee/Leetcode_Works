#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
//https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/submissions/
int function(string S)
{
    /*
    Count number of brakets 
    */
    int xy = 0;
    bool flip = 0;
    int sec = 0;
    vector<int> seq;
    seq.push_back(0);

    for (auto &ch : S)
    {
        //cout << ch << " ";
        if (ch == '(')
        {
            if(flip == 0){
                seq[sec]++;
            }
            else{
                flip = 0;
                sec++;
                seq.push_back(1);
            }
        }
        else if (ch == ')')
        {
            if(flip == 1){
                seq[sec]++;
            }
            else{
                flip = 1;
                sec++;
                seq.push_back(1);
            }
        }
    }

    int x_hang = 0, y_hang = 0;
    int i = 0;
    if( S[0] == ')'){
        y_hang = seq[0];
        i++;
        //seq.erase(seq.begin());
    }

    for (; i < seq.size(); i++){
        //cout << "\n "<< seq[i] << "\n";
        if(i%2 == 0 ){
            x_hang += seq[i];
        }
        else{
            if(seq[i] < x_hang){
                xy += seq[i];
                x_hang -= seq[i];
            }
            else{
                xy += x_hang;
                y_hang = seq[i] - x_hang;
                x_hang = 0;
            }
        }
    }

    //cout << "\n x_hang:" << x_hang << " y_hang:" << y_hang << " xy: "<<xy<< " \n";


    return (S.length() - (xy*2) );
}

int main()
{

    /*printf("Hello World \n");
Example 1:
Input: "())"
Output: 1

Example 2:
Input: "((("
Output: 3

Example 3:
Input: "()"
Output: 0

Example 4:
Input: "()))(("
Output: 4
    */

    /*
    Go through all strings; all pairs need an open braket and a close braket to the left of it
        if curr character is an open braket; go left to find its pair
            if found a potential pair; check with xy pair
                if this pot pair passed # > xy pair; add +1 to xy
                else no pair has been found; jump to next character
                    (potential skip by implimenting bool saying no more pairs avaliabe; just keep counting)

    end calc
        ~~find # of hanging x by (x - xy)~~
        find # of hanging x or y by ( str.length - (xy*2) )
            we can infer all x and y are the sum that isnt in the pair


    count in a vector all x and y

    if      x...y       | y...x     | x1.y1.x2.y2   |
    x > y | xy = y      | xy = 0    | xy = y        |
    x = y | xy = x & y  | xy = 0    | xy =          |
    x < y | xy = x      | xy = 0    | xy =          |

    vector collects and catagorizes a sequence of x's and y's
        if pattern xy 
            x vectors gets pushed and x_tot += x;
            y vectors that come after gets pushed

                if y > x_tot => remaining y are hanging
                    x_tot = 0;
                else
                    the x_tot -= y vector
            repeat till end of str
            
        else if pattern yx
            all first y are hanging and reverts back to xy

        if finishing char is x; all x are hanging
        else if finishing char is y; sub and all y are hangings
    

            //find pairs
            // int a = 0;
            // for(int i = x+y; i < s.length();i++){
            //     if(s.at(i) == ')'){
            //         if(a > xy || xy == 0){
            //             xy++;
            //             break;
            //         }
            //         else
            //             a++;
            //     }
            // }

    */
    string s = "()()";
    printf("1: %d == 0\n", function(s));

    s = ")(";
    printf("2: %d == 2\n", function(s));

    s = "())";
    printf("2.5: %d == 1\n", function(s));

    s = "(((";
    printf("3: %d == 3\n", function(s));

    s = "()))((";
    printf("4: %d == 4\n", function(s));

    return 0;
}