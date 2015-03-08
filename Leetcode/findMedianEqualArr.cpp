#include <iostream>
using namespace std; 
double findMedianSortedArrays(int A[], int m, int B[], int n) {
	if(A[(m-1)/2] == B[(n-1)/2]){
		return A[(m-1)/2];
	}
	if(m == 1){
		return A[0] > B[0] ? B[0] : A[0];
	}
  if(A[(m-1)/2] < B[(n-1)/2]){
		findMedianSortedArrays(&A[m-(m-1)/2-1], ((m-1)/2+1), &B[0], (n-1)/2+1);
	} else {
	  findMedianSortedArrays(&A[0], ((m-1)/2+1), &B[n-(n-1)/2-1], (n-1)/2+1);
	}
	
		
}
int main() {
	int A[] = {1, 3, 5, 7, 9};
	int B[] = {2, 4, 6, 8, 10};
	int ans;
	ans = findMedianSortedArrays(A, 5, B, 5);
	cout << ans;
	return 0; 
} 
