#include <iostream>
#include <string>
using namespace std;
int lengthOfLongestSubstring(string s) {
  int n = s.length();
  int i = 0, j = 0;
  int maxLen = 0;
  bool exist[256] = { false };
  while (j < n) {
    if (exist[s[j]]) {
      maxLen = max(maxLen, j-i);
      while (s[i] != s[j]) {
        exist[s[i]] = false;
        i++;
        cout << i <<endl;
      }
      i++;
      cout << i <<endl;
      j++;
    } else {
      exist[s[j]] = true;
      j++;
    }
  }
  maxLen = max(maxLen, n-i);
  return maxLen;
}
/*int lengthOfLongestSubstring(string s) {
    int n = s.length();
	//char b[1000] = s;
	bool a[257] = {false};
	int i = 0;
	int j = 0, num = 0;
	while (i < n){
		if(a[s[i]]== false){
			a[s[i]]= true;
		} else {
			break;
		}
		i++;
	}
	//cout << "done"<<endl;
	while(j < 257){
		if(a[j] == true) {
			num++;
		}
		j++;
	}
	return num;
} */
int main() {
	string s;
	cin >> s;
	
	cout << lengthOfLongestSubstring(s) << endl;
	return 0;
	
}
