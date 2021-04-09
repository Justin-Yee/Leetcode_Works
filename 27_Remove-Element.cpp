#include <stdio.h>
// #include <iostream>
// #include <string>
#include <vector>

using namespace std;

    int removeElement(vector<int>& nums, int val) {



        for(int itr = nums.size(); itr > 0 ;itr--){
            if(nums.front() != val){
                nums.push_back(nums.front());
            }
            nums.erase(nums.begin());
        }


        return nums.size();
    }

int main()
{
    /*
    Input a vect of ints and # you want removed

    remove #; return new length of vector

    */

    printf("Hello World \n");

    vector<int> input = {};
    printf(" 0 = %d",removeElement(input,1));

    return 0;
}
