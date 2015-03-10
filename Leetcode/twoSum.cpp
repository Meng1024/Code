#include <iostream>
#include <vector>
#include <map>

using namespace std;
vector<int> twoSum(vector<int> &numbers, int target) {
	vector<int> res ;
	map<int, int> hmap;
	for(int i = 0; i < numbers.size(); i++){
		hmap[numbers[i]] = i;
	}
	for(int i = 0; i < numbers.size(); i++){
		if(hmap.find(target - numbers[i]) != hmap.end() ){
			if(i < hmap[target - numbers[i]]) {
				res.push_back(i+1);
				res.push_back(hmap[target - numbers[i]] + 1);
				return res;
			} 
			if(i > hmap[target - numbers[i]]){
				res.push_back(hmap[target - numbers[i]] + 1);
				res.push_back(i+1);
				return res;
			}
		} 
	}
	//return res;
}
int main(){
	int s[] = {2, 8, 7, 15};
	vector<int> num;
	num.assign(s, s+sizeof(s)/sizeof(int));
	vector <int> result = twoSum(num, 9);
 	vector <int> :: iterator it = result.begin();
	while(it != result.end()){
		cout << ' ' << *it;
		it++;
	}
	return 0;
}
  
