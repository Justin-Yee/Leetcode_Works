#include <stdio.h>
// #include <iostream>
// #include <string>
#include <vector>

using namespace std;

void print_out(vector<int>& A){
    for (auto &ch : A){
        printf(" %d ",ch);
    }
    printf("\n");
}

vector<int> sortArrayByParityII(vector<int>& A)
{
    for (int i = 0; i < A.size(); i++){
        //pose to be even
        if(i%2 == 0){
            //check if not even
            if(A[i]%2 != 0){
                //Find next even and swap
                for(int j = i+1; j < A.size(); j+=2){
                    if(A[j]%2 == 0){
                        int temp = A[i];
                        A[i] = A[j];
                        A[j] = temp;
                    }
                }
            }
        }
        //pose to be odd
        else{
            //check if not even
            if(A[i]%2 == 0){
                //Find next even and swap
                for(int j = i+1; j < A.size(); j+=2){
                    if(A[j]%2 != 0){
                        int temp = A[i];
                        A[i] = A[j];
                        A[j] = temp;
                    }
                }
            }
        }
    }
    return A;
}

int main()
{

    printf("Hello World \n");
    vector<int> arr = {4,2,5,7};//{3,4,3,4};
    print_out(arr);
    vector<int> arr2 = sortArrayByParityII(arr);
    print_out(arr2);

    return 0;
}