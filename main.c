//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int z=5;
    struct node a,b,c,*tail,*head, x;
    a.value = z;
    a.next=&b;
    head=&a;
    b.value=head->value+3;

    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8
/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
 */
    b.next = &c;
    head->next->next->value = 11;
    head->next->next->next = NULL;
    printf("%d\n", head->next->next->value);
    
/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
    
        
*/
    head = &x;
    x.next = &a;
    x.value = 2;
    printf("\n\nx = %d\n", x.value);
    printf("x = %d\n", head->value);
    printf("a = %d\n", head->next->value);
    printf("b = %d\n", head->next->next->value);
    printf("c = %d\n", head->next->next->next->value);

    typedef struct node* NodePtr;
    NodePtr tmp=head; //add temp value to faciliate

    /*  Exercise III Use loop to print everything
        int i,n=5;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
          // What is missing???
        }
    */
    int i, n=4;
    for (i = 0; i < n; i++)
    {
        printf("%3d", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");

   /*  Exercise IV change to while loop!! (you can use NULL to help)
       
         while(){
            printf("%3d", tmp->value);
           // What is missing???
        }
    */
    tmp=head;
    while (tmp != NULL)
    {
        printf("%3d", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");


 /*  Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
          
     */
    NodePtr newhead, newtmp;
    newhead = (NodePtr)malloc(sizeof(struct node));
    newtmp = newhead;
    int j;
    for (int i = 0, j = 2; i < 4; i++, j+=3)
    {
        if (i == 3)
            newtmp->next = NULL;
        else
            newtmp->next = (NodePtr)malloc(sizeof(struct node));
        newtmp->value = j;
        printf("%d\n", newtmp->value);
        newtmp = newtmp->next;
    }

    newtmp = newhead;
    while (newtmp != NULL)
    {
        printf("%3d", newtmp->value);
        newtmp = newtmp->next;
    }
    printf("\n");
    /*  Exercise VI Free all node !!
         //use a loop to help
          
     */

    while (newhead)
    {
        newtmp = newhead;
        newhead = newhead->next;
        free(newtmp);
    }
    
    return 0;
}
