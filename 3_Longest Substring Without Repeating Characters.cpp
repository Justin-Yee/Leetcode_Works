#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void func2(vector<string> temp){
    for(int i = 0; i < temp.size(); i++){
        printf("%d: %s\n",i,&temp[i][0]);
    }
    return;
}

int function(string s){

    if(s.length() == 0)
        return 0;
    
    vector<string> temp;
    temp.push_back("");
    int a = 0;
    temp[a].push_back(s[0]);

    for(int i = 1; i < s.length(); i++){
        //for length of input
    size_t found = temp[a].find(s.at(i));
    if (found != string::npos){
        //if found; substr not unique; start over
        a++;   
        if(found+1 < i){
        temp.push_back(temp[a-1].substr(found+1,temp[a-1].length()));
        }
        else
            temp.push_back("");

        temp[a].push_back(s[i]);
    }
    else{
        //else add to curr str length
        temp[a].push_back(s[i]);
    }
    }

    func2(temp);

    //find longest str
    int biggest = 0;
    int at = 0;
    for(int i = 0; i < temp.size(); i++){
        if(temp[i].size() > biggest){
            biggest = temp[i].size();
            at = i;
        }
    }

    return temp[at].size();
}

int main(){
    
    /*
            printf(" found: %d; length: %d; int i: %d\n",found,temp[a-1].length(),i);
            
        printf("Hello World \n");
        return 0;

        Input: s = "abcabcbb"
        Output: 3
        Explanation: The answer is "abc", with the length of 3.

        Input: s = "bbbbb"
        Output: 1
        Explanation: The answer is "b", with the length of 1.
        Example 3:

        Input: s = "pwwkew"
        Output: 3
        Explanation: The answer is "wke", with the length of 3.
        Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
    */

   string s = "dvdf";

   printf("1: Output %d\n\n",function(s));

   s = "vddf";
   printf("2: Output %d\n\n",function(s));
   
//    s = "pwwkew";
//    printf("3: Output %d\n\n",function(s));

//    s = "";
//    printf("4: Output %d\n\n",function(s));


return 0;
}