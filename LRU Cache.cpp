#include <iostream>
#include <list>
#include <map>


using namespace std;

class LRUCache{

private:
	list<int> used;
	map<int,list<int>::iterator> cache;
	int _capacity;


	void touch(list<int>::iterator it){
		int key = *it;
		used.erase(it);
		used.push_front(key);
		cache[key] = used.begin();
	}

public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if(it==cache.end()) return -1;
        touch(it->second);
        return *(it->second);
    }
    
    void set(int key, int value) {
    	auto it = cache.find(key);
        if(it != cache.end()) touch(it->second);
        else{
        	if(cache.size()==capacity){
        		cache.erase(used.back());
        		used.pop_back();
        	}
        	used.push_front(value);
        }
        cache[key] = used.begin();


    }
};

int main(){

}