#LeetCode

##twoSum
这里有 vector hash的基本应用

比如 vector中: 可以定义iterator去遍历vector

map中: 可以用find 函数去查key 如果不存在则返回end();

最后在twoSum这个函数中，注意res的位置， 因为会重复返回比如第1个位置和第3个位置，那么在第一个位置的时候push一次在第三个位置的时候push了一次。
