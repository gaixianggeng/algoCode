#include "algoCode.h"
#include <utility>
#include <list>
#include <unordered_map>
//最小栈
class MinStack {
	public:
		/** initialize your data structure here. */
		MinStack() {
		}

		void push(int x) {
			if (st.size()== 0){
				st.push({x,x});
			}else{
				st.push({x,min(x,st.top().second)});
			}
		}

		void pop() {
			st.pop();
		}

		int top() {
			return st.top().first;
		}

		int getMin() {
			return st.top().second;
		}

	private:
		stack<pair<int, int>> st;

};
//LRU缓存机制
//最近最少使用
//双向链表+hash
class LRUCache {
	public:
		LRUCache(int capacity) {
			this->cap = capacity;


		}

		int get(int key) {
			auto it = map.find(key);
			if (it == map.end()){
				return -1;
			}
			pair<int,int> temp = *map[key];
			cache.erase(map[key]);
			cache.push_front(temp);
			//这一步不能省略 相当于map存储的对应的地址
			// cache不能直接获取数据 
			map[key] = cache.begin();
			return temp.second;
		}

		void put(int key, int value) {

			auto it = map.find(key);
			//key不存在的话
			if (it == map.end()){
				if (map.size() == cap){
					auto last = cache.back();
					int key = last.first;
					map.erase(key);
					cache.pop_back();
				}
				cache.push_front(make_pair(key,value));
				map[key] = cache.begin();
			}else{
				cache.erase(map[key]);
				cache.push_front(make_pair(key,value));
				map[key] = cache.begin();
			}

		}

	private:
		int cap;
		//双链表 转kv元组
		list<pair<int, int>> cache;
		//哈希表：key 映射到cache中
		unordered_map<int,list<pair<int,int>>::iterator> map;
};
