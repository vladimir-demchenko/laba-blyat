#ifndef __OBJECT_H
#define __OBJECT_H
#include <string>
#include <vector>

using namespace std;

class Object {
public: 
	int ready;
	int type;
	string name;
	vector<Object> objects;
	Object* root;
	Object(Object* root, string name, int ready);
	Object(Object* root, string name);
	Object* getObject(string path_s);
	Object* getUniqueObject(string name);
	void add(string name, int ready, int type);
	void displayNode(int level);
};
vector<string> split(string s);
string getTabs(int num);
#endif