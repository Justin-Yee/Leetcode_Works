#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

string form_ans(int num1, int num2){
    string ans = "";
    ans.append(to_string(num1));

    if(num2 != num1){
        ans.append("->");        
        ans.append(to_string(num2));
    }
    return ans;
}

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ans;
    //case 0
    if(nums.size() == 0){
        return ans;
    }
    //case 1
    if(nums.size() == 1){
        ans.push_back(form_ans(nums[0],nums[0]));
        return ans;
    }

    //case: 2 or more
    int start = nums.front();
    for(int i = 0; i < nums.size();i++){
        if(i == nums.size()-1){//last num case
            ans.push_back(form_ans(start,nums[i]));
            continue;
        }

        if(nums[i]+1 == nums[i+1] ){
            //if still in sequence; continue
        }
        else{
            //else write to ans
            ans.push_back(form_ans(start,nums[i]));
            start = nums[i+1];
        }
    }

    return ans;
}

int main()
{

    printf("Hello World \n");

    vector<int> input = {-2147483648,-2147483647,2147483647};

    vector<string> output = summaryRanges(input);
    for(int i = 0; i < output.size(); i++){
        cout << i <<": "<< output[i] <<"\n";
    }
    cout << "\n";
    
    input = {-1};

    output = summaryRanges(input);
    for(int i = 0; i < output.size(); i++){
        cout << i <<": "<< output[i] <<"\n";
    }
    cout << "\n";

    input = {0,1,2,4,5,7};

    output = summaryRanges(input);
    for(int i = 0; i < output.size(); i++){
        cout << i <<": "<< output[i] <<"\n";
    }
    cout << "\n";

    input = {0,1,2,3,4,5};

    output = summaryRanges(input);
    for(int i = 0; i < output.size(); i++){
        cout << i <<": "<< output[i] <<"\n";
    }
    cout << "\n";

    input = {0};

    output = summaryRanges(input);
    for(int i = 0; i < output.size(); i++){
        cout << i <<": "<< output[i] <<"\n";
    }
    cout << "\n";

    input = {};

    output = summaryRanges(input);
    for(int i = 0; i < output.size(); i++){
        cout << i <<": "<< output[i] <<"\n";
    }
    cout << "\n";
    return 0;
}
