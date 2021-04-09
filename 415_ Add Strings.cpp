#include <stdio.h>
#include <iostream>
#include <string>
// #include <vector>

using namespace std;

string addStrings(string num1, string num2)
{
    char *it1 = new char();
    char *it2 = new char();
    int str_Size[] = {0,0};

    if(num1.size() >= num2.size()){
        it1 = &num1[0];
        it2 = &num2[0];
        str_Size[0] = num1.size();
        str_Size[1] = num2.size();
    }
    else{
        it1 = &num2[0];
        it2 = &num1[0];
        str_Size[0] = num2.size();
        str_Size[1] = num1.size();
    }

    string ans = "";
    bool carry_over = false;
    for(int i = 0; i < str_Size[0]; i++){
    
    // printf("%d : ",i);
    // cout << *(it1+str_Size[0]-i-1) << " + ";
    // cout << it2[str_Size[1]-i-1]<< " = ";

    if(i < str_Size[1]){
        int temp = (*(it1+str_Size[0]-i-1))-48 + (*(it2+str_Size[1]-i-1))-48;
        if(carry_over){
            temp++;
            carry_over = false;
        }
        if(temp >= 10){
            temp -= 10;
            carry_over = true;
        }
        string temp2 = "";
        temp2.append(1,(temp+48));
        ans.insert(0,temp2);
        //printf("a: %d",temp);
    }
    else{
        int temp = (*(it1+str_Size[0]-i-1))-48;
        if(carry_over){
            temp++;
            carry_over = false;
        }
        if(temp >= 10){
            temp -= 10;
            carry_over = true;
        }
        string temp2 = "";
        temp2.append(1,(temp+48));
        ans.insert(0,temp2);
        //printf("b: %d",temp);
    }
    //printf("\n");
    }

    if(carry_over){
        string temp2 = "";
        temp2.append(1,(48));
        ans.insert(0,temp2);
    }

    return ans;
}

int main()
{
    /*
    Find str w/ greatest size and set as Str1
        other as Str2
    bool carryOver

    for (all of Str1 ){
        temp_Int = Convert to int ( Str1[i] + Str2[i] )
        if(Carry Over)
            temp_Int + 1
            CarryOver Fasle
        
        if( temp_Int > 10)
            Substract 10
            CarryOver True
            
        append to Str3( temp_Int)

        if( not end of str) 
            go to next Str1 & Str2
        else
            point to 0
        
    }

    if(CarryOver){
        append Str3(1)
        CarryOver = false
    }

    return Str3;
    */

    printf("Hello World \n");
    cout << addStrings("19","1") << "\n";
    return 0;
}