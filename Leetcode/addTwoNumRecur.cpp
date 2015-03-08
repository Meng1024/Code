 #include <iostream>
 using namespace std;
 
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
 ListNode * nt(ListNode *p) {
 	if(!p) return NULL; 
	return p->next;
 }
 
 ListNode *stack(ListNode *l1, ListNode *l2, int carry){
	if(!l1 && !l2 && carry == 0) return NULL;
 	if(l1) carry += l1->val;
	if(l2) carry += l2->val;
	ListNode *p = new ListNode(carry % 10);
    p->next = stack(nt(l1), nt(l2), carry / 10);
    return p;
 }
 ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
      return stack(l1, l2, 0);
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
