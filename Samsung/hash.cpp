#include <iostream>
#include <vector>
#include <functional>
using namespace std;
using element = pair<string,string>; 

/*
size_t getHash(const char *key, size_t mSize)
{
	size_t ret = 4321;
	while(*key)
		ret = ((ret << 5) + ret + *key++) % mSize;
	return ret;		
}
*/

struct HashMap
{
	size_t mSize;
	vector<vector<element>> record;

	HashMap(size_t mSize) : mSize(mSize){
		record.assign(mSize,vector<element>());
	}
		
	element* find(const string& key)
	{
		size_t h = hash<string>{}(key) % mSize;
		
		for(auto& ele : record[h])
			if(ele.first == key)
				return &ele;
		
		return nullptr;		
	}

	void insert(const string& key, const string& val)
	{
		auto ptr = this->find(key);
		
		if(ptr)
			ptr->second = val;
		else{
			size_t h = hash<string>{}(key) % mSize;
			record[h].push_back({key,val});	
		}
	}
};

int main(int argc, char* argv[])
{
	HashMap hMap(1024);
	
	hMap.insert("a","aaaa");

	auto ptr = hMap.find("a");
	if(ptr)
		cout << ptr->second << endl;
	else
		cout << "not found" << endl;	

	return 0;
}
