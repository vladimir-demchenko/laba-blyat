#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include "object.h"
#include "obj1.h"
#include "obj2.h"
#include "obj3.h"
#include "obj4.h"
#include "obj5.h"

vector<string> split(string s) {
	string line = s;
	vector<string> tokens;
	stringstream check1(line);
	string intermediate;
	while (getline(check1, intermediate, '/')) {
		tokens.push_back(intermediate);
	}
	return tokens;
}

string getTabs(int num) {
	string tabs = "";
	for (int i = num; i != 0; i--) {
		tabs+= "    ";
	}
	return tabs;
}

using namespace std;

Object::Object(Object* root, string name, int ready) {
	this->root = root;
	this->name = name;
	this->ready = ready;
}

Object::Object(Object* root, string name) {
	this->root = root;
	this->name = name;
}

Object* Object::getObject(string path_s) {
	vector<string> path = split(path_s);
	for (auto it = path.begin(); it != path.end(); it++) {
		if (it->empty())
			path.erase(it);
	}
	if (path[0] != this->name) {
		return nullptr;
	}
	path.erase(path.begin());
	
	Object* ob = this;
	for (auto a:path) {
		bool flag = false;
		for (auto & object: ob->objects) {
			if (object.name == a) {
				ob = &object;
				flag = true;
				break;
			}
		}
		if (!flag) {
			ob = nullptr;
			break;
		}
	}
	return ob;
}
		
Object* Object::getUniqueObject(string name) {
	if (name == this->name) {
		return this;
	}
	if (objects.end() == objects.begin()) {
		return nullptr;
	}
	for (auto & object : objects) {
		if (object.name == name) {
			return &object;
		}
	}
	for (auto &object: objects) {
		if (object.getUniqueObject(name) != nullptr) {
			return object.getUniqueObject(name);
		}
	}
	return nullptr;
}

void Object::add(string name, int ready, int type) {
	switch(type) {
		case 1: {
			Object1 o = Object1(name, ready);
			objects.emplace_back(o);
			return;
		}
		case 2: {
			Object1 o = Object1(name, ready);
			objects.emplace_back(o);
			return;
		}
		case 3: {
			Object2 o = Object2(name, ready);
			objects.emplace_back(o);
			return;
		}
		case 4: {
			Object3 o = Object3(name, ready);
			objects.emplace_back(o);
			return;
		}
		case 5: {
			Object4 o = Object4(name, ready);
			objects.emplace_back(o);
			return;
		}
		case 6: {
			Object5 o = Object5(name, ready);
			objects.emplace_back(o);
			return;
		}
	}
}

void Object::displayNode(int level) {
	if (level != 0) {
		cout << endl;
	}
	cout << getTabs(level) << this->name;
	for (auto & ob : objects) {
		ob.displayNode(level+1);
	}
}

