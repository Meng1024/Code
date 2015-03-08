#include <stdio.h>
//using namespace std;
#include "linkedList.h"
int main (){
    struct linkedList* l1;
    struct linkedList* l2;
    struct linkedList* res;
    int flag = 0;
    l1 = createLinkedList();
    l2 = createLinkedList();
    res = createLinkedList();
    addFrontList(l1, 1);
    
    addFrontList(l2, 4);
    addFrontList(l2, 5);
    addFrontList(l2, 6);
    addFrontList(l2, 7);
    printf("done\n");
    
    
    struct DLink *p;
    p = l2->firstLink->next;
    while (p != l2->lastLink) {
        printf("%d\n", p->value);
        p = p->next;
    }
    
    
    
    
    struct DLink  *p1;
    struct DLink  *p2;
    p1 = l1->firstLink->next;
    p2 = l2->firstLink->next;
	while (p1 != l1->lastLink && p2 != l2->lastLink)
    {
        if (p1 -> value + p2->value >= 10){
            addBackList(res, p1->value + p2->value + flag - 10);
            flag = 1;
        } else {
            addBackList(res, p1->value + p2->value + flag);
            flag = 0;
        }
        p1 = p1->next;
        p2 = p2->next;
        
    }
    
    
    printf("done\n");
    /*
    struct DLink *m;
    m = res->firstLink->next;
    while (m != res->lastLink) {
        printf("%d\n", m->value);
        m = m->next;
    }
     */
    while (p2 != l2->lastLink){
        addBackList(res, p2->value);
        p2 = p2-> next;
    }
    
    while (p1 != l1->lastLink){
        addBackList(res, p1->value);
        p1 = p1 -> next;
    }
    
    
    struct DLink *p3;
    p3 = res->firstLink->next;
    while (p3 != res->lastLink) {
        printf("%d\n", p3->value);
        p3 = p3->next;
    }
	return 0;
}
