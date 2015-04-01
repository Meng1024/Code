#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slp.h"
#include "util.h"
#include "prog1.h"

typedef struct table *Table_;
typedef struct IntAndTable *IntAndTable_;
struct table{
	string id; 
	int value; 
	Table_ tail;
};

struct IntAndTable{
	int i;
	Table_ t;
};


int max(int a, int b) {return a > b ? a : b;}
int maxargs(A_stm s);
int maxargsExp(A_exp e);
Table_ interpStm(A_stm s, Table_ t);
IntAndTable_ interpExp(A_exp e, Table_ t);


//Qestion2 mapping the identier to the table
//constructor of table
Table_ Table(string id, int value, struct table *tail){
	Table_ t = malloc(sizeof(*t));
	t->id = id;
	t->value = value;
	t->tail = tail;
	return t;
}

IntAndTable_ IntAndTable(int value, Table_ t){
	IntAndTable_ iat = malloc(sizeof(*t));
	iat->i = value;
	iat->t = t;
	return iat;
}



IntAndTable_ interpExp(A_exp e, Table_ t){
	int value;	
	IntAndTable_ iat1, iat2;
	Table_ t1;
	switch(e->kind){
	case A_idExp : 
		value = lookup(t, e->u.id);	
    return IntAndTable(value, t);
	case A_numExp : return IntAndTable(e->u.num, t);
	case A_opExp :
		iat1 = interpExp(e->u.op.left, t);
		iat2 = interpExp(e->u.op.right, iat1->t); 
		
		switch(e->u.op.oper) {
		case A_plus  : value = iat1->i + iat2->i; break;
		case A_minus : value = iat1->i - iat2->i; break;
		case A_times : value = iat1->i * iat2->i; break;
		case A_div   : value = iat1->i / iat2->i; break;
		} 
    return IntAndTable(value, iat2->t);
	case A_eseqExp: 
	  t1 = interpStm(e->u.eseq.stm, t);
		return interpExp(e->u.eseq.exp, t1);				
	}
}


Table_ interpStm(A_stm s, Table_ t){
	Table_ t1;
	IntAndTable_ iat;
	A_expList exps;
	switch (s->kind){
		case A_compoundStm : 
      t1 = interpStm(s->u.compound.stm1, t);
			interpStm(s->u.compound.stm2, t1); break;
		case A_assignStm : 
			iat = interpExp(s->u.assign.exp, t);return Table(s->u.assign.id, iat->i, iat->t);
		case A_printStm : 
				  exps = s->u.print.exps;
          while(exps->kind != A_lastExpList) {
              iat = interpExp(exps->u.pair.head, t);
              printf("%d ", iat->i);
  
              exps = exps->u.pair.tail;
              t = iat->t;
          }
          iat = interpExp(exps->u.last, t);        
          printf("%d\n", iat->i);
          return iat->t;
  }
	

}

Table_ update(string id, int value, Table_ t){
	return Table(id, value, t);
}

int lookup(Table_ t, string key){
	while(t != NULL){
		if(strcmp(key, t->id)== 0){
			return t->value;
		}
		t = t->tail;
	}
	return 0;
}



//Question 1: compute the number of the parameters in print functions
int maxargsExp(A_exp e) {
  int a, b;
	switch(e->kind) {
	case A_idExp: return 0;
  case A_numExp : return 0;
  case A_opExp :
    a = maxargsExp(e->u.op.left);
    b = maxargsExp(e->u.op.right);
    return max(a, b);
  case A_eseqExp :
    a = maxargs(e->u.eseq.stm);
    b = maxargsExp(e->u.eseq.exp);
    return max(a, b);  
	}
}

int maxargs(A_stm s) {
  int a, b, cur, tmp;
  switch(s->kind) {
  case A_compoundStm:
    a = maxargs(s->u.compound.stm1);
    b = maxargs(s->u.compound.stm2);
		return max(a, b);
  case A_assignStm:
		return maxargsExp(s->u.assign.exp);
  case A_printStm:
    cur = 1;
    A_expList es = s->u.print.exps;
    while(es->kind != A_lastExpList) {
			cur++;
			es = es->u.pair.tail;
    }
		
    es = s->u.print.exps;
    while(es->kind != A_lastExpList) {
      tmp = maxargsExp(es->u.pair.head);
      if(tmp > cur) cur = tmp;
			es = es->u.pair.tail;
    }
    
    tmp = maxargsExp(es->u.last);
    if(tmp > cur) cur = tmp;

    return cur;
  }
}



int main(){
  A_stm s1 = A_CompoundStm(
		A_PrintStm(A_LastExpList(A_IdExp("b"))),
		A_CompoundStm( A_PrintStm(A_PairExpList( A_IdExp("a"), A_PairExpList( A_IdExp("a"), A_LastExpList(A_IdExp("b"))))),
			A_PrintStm(A_PairExpList(A_IdExp("a"), A_LastExpList(A_IdExp("b"))))
			));


   A_stm s2 = A_CompoundStm( A_PrintStm(A_PairExpList( A_IdExp("a"), A_PairExpList( A_IdExp("a"), A_LastExpList(A_IdExp("b"))))),
			A_PrintStm(A_PairExpList(A_IdExp("a"), A_LastExpList(A_IdExp("b"))))
			);

A_stm s3 = A_CompoundStm( A_PrintStm(A_PairExpList( A_IdExp("a"), A_PairExpList( A_IdExp("a"), A_LastExpList(A_IdExp("b"))))), A_AssignStm("a",A_NumExp(5)));

A_stm s4 = A_PrintStm(A_PairExpList( A_IdExp("a"), A_LastExpList( A_EseqExp(A_PrintStm(A_PairExpList( A_IdExp("a"), A_PairExpList( A_IdExp("a"), A_LastExpList(A_IdExp("b"))))), A_IdExp("a")) )));

	A_stm s = prog();
  interpStm(s, NULL);
	
	int res = maxargs(s);
	int res1 = maxargs(s1);
	int res2 = maxargs(s2);	
	int res3 = maxargs(s3);	
  int res4 = maxargs(s4);	

	printf("%d %d %d %d %d\n", res, res1, res2, res3, res4);

	return 0;
}
