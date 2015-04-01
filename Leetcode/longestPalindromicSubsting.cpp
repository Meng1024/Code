#include <iostream>
#include <cstring>
using namespace std;

//O(N^2)complexivity O(N^2)space
string longestPalindrome(string s) {
	int size = s.length();
	bool table[1000][1000] ={false};
	int i,j, maxlen = 1;
	int longestBegin = 0;
	for(i = 0; i < size; i++){
		table[i][i] = true;
		maxlen = 1;	
	}
  for(i = 0; i < size-1; i++){
		if(s[i] == s[i+1]){
			table[i][i+1] = true;
			maxlen = 2;
			longestBegin = i;
		}
	}
	//cout << maxlen <<endl;
	for(int len = 3; len <= size ; len++){
		for(i= 0; i < size -len + 1; i++) {
			j = i + len - 1;
			if(s[i] == s[j] && table[i+1][j-1]){
				longestBegin = i;
				maxlen = len;
				table[i][j] = true; 
				//cout << maxlen <<endl;
			}
		}
	}
	return s.substr(longestBegin, maxlen);
}
//O(N^2) complexivity O(1) space 
string compute(string s, int i, int j){
	while(i >= 0 && j < s.length() && s[i] == s[j]){	
			i--;
			j++;
	}
	return s.substr(i+1, j-i-1);
}
string lps(string s) {
	int i;
	int len = s.length();
	string s1 = s.substr(0,1);
	string s2;
	if (s.length() == 0){
		return " ";	
	}
	for(i = 0; i < len; i++) {
		s2 = compute(s, i, i);
		if(s2.length() > s1.length()){
			s1 = s2;		
		}
		s2 = compute(s, i, i+1);
		if(s2.length() > s1.length()){
			s1 = s2;		
		}
	}
	return s1;
}

//nlogn complexivity
// will be implemented in the future also the O(n) algorithm.

string mergePS(string s, int i, int j){
	while(i >= 0 && j < s.length() && s[i] == s[j]){	
			i--;
			j++;
	}
	cout << s.substr(i+1, j-i-1) <<endl;
	return s.substr(i+1, j-i-1);
}
string longPS(string s){

	string s1, s2, s3;
	string	maxS = s1;
	int m = s.length();
	if(m = 2 && s[0] == s[1]) return s.substr(0,2);
	if(m = 1) return s.substr(0,1);
	if(m < 1) return "";
	
	int n = s.length()/2;
	s1 = longPS(s.substr(0, n));
	s2 = longPS(s.substr(n, n));
	s3 = mergePS(s, n-1, n-1);
	maxS = s1.length() > s2.length() ? s1 : s2;
	maxS = maxS.length() > s3.length() ? maxS : s3;
	cout << maxS<< endl;
	s3 = mergePS(s, n-1, n);
	maxS = s1.length() > s2.length() ? s1 : s2;
	maxS = maxS.length() > s3.length() ? maxS : s3;
	return maxS;
}

int main(){
	string s;
	string s1 = "abac";
	s = longestPalindrome(s1);
	cout << s << endl;	
	s = lps(s1);
	cout << s << endl;
	s = longPS(s1);
	cout << s << endl;
	return 0;
}
