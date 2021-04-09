#include <stdio.h>
#include <math.h>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode l3;
ListNode* function(ListNode* l1, ListNode* l2){
    bool carryOver  = 0;
    while(true){
        int temp = l1->val + l2->val;
        if(carryOver){
            temp++;
            carryOver = 0;
        }
        if(temp > 10){
            carryOver = 1;
            temp -= 10;
        }
        l3.val = temp;
        
        printf("l3.val: %d, carryOver: %d\n",temp,carryOver);

        if(l1->next == nullptr && l2->next == nullptr){
            if(carryOver == 1){
                ListNode temp(1);
                l3.next = &temp;
            }
            else
                break;
        }

        l1 = l1->next;
        l2 = l2->next;
    }
    return &l3;
}

int main(){
    
    /*
        printf("Hello World \n");
        return 0;
    */

   ListNode A(3);
   ListNode B(6);
   ListNode C(3);

   B.next = &C;
   A.next = &C;

   function(&A,&B);



return 0;
}