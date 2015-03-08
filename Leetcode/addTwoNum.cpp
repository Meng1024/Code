 #include <iostream>
 using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };


 ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
       int sum;
       int flag = 0;
       ListNode *p1 = NULL, *ret;
       if(l1 == NULL) {return l2;}
       if(l2 == NULL) {return l1;}
       while(l1 && l2){
           if(l1->val + l2->val + flag >= 10) {
               if(p1 == NULL) {
                   ret = p1 = new ListNode(l1->val + l2->val + flag - 10);
                   flag = 1;
               } else {
                   p1->next = new ListNode(l1->val + l2->val + flag - 10);
                   p1 = p1 -> next;
                   flag = 1;
               }
           } else {
              if(p1 == NULL) {
                   ret = p1 = new ListNode(l1->val + l2->val + flag);
                   flag = 0;
               }else {
                   p1->next =  new ListNode(l1->val + l2->val + flag);
                   p1 = p1 -> next;
                   flag = 0;
               }

          }


          l1 = l1->next;
          l2 = l2->next;
       }

       while(l1 != NULL) {
       		if(l1->val == 9 && flag == 1){
        	   p1->next = new ListNode(0);
        	   p1 = p1 -> next;
        	   flag = 1;
       		}else {
				p1->next = new ListNode(l1->val + flag);
				p1 = p1 -> next;
				flag = 0;
			}
           l1 = l1->next;
       }
       while(l2 != NULL) {
       		if(l2->val == 9 && flag == 1){
        	   p1->next = new ListNode(0);
        	   p1 = p1 -> next;
        	   flag = 1;
       		}else {
				p1->next = new ListNode(l2->val + flag);
				p1 = p1 -> next;
				flag = 0;
			}
           l2 = l2->next;
       }
       if(flag == 1){
		  p1 ->next = new ListNode(1);
	   }
       return ret;
}



int main() {

	ListNode *l1 = new ListNode(9);
	l1-> next = new ListNode(9);
	l1->next->next = new ListNode(9);
	l1->next->next ->next = new ListNode(9);
	ListNode *l2 = new ListNode(1);
	ListNode  *res =addTwoNumbers(l1, l2);
	while (l1 != NULL){
		cout << l1 ->val;
		l1 = l1 -> next;
	}
	cout << endl;
	while (l2 != NULL){
		cout << l2 ->val;
		l2 = l2 -> next;
	}
	cout << endl;


	while (res != NULL){
		cout << res ->val;
		res = res -> next;
	}
	return 0;
}
