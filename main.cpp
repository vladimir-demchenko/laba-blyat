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
	
using namespace std;

int main() {
	cout << "Object tree" << endl;
	string name;
	cin >> name;
	auto* root = new Object(nullptr, name);
	while (true) {
		string pName;
		cin >> pName;
		if (pName == "endtree") {
			break;
		}
		string oName;
		cin >> oName;
		int type;
		cin >> type;
		int ready;
		cin >> ready;
		auto ob = root->getObject(pName);
		ob->add(oName, ready, type);
	}
	root->displayNode(0);
	
	while (true) {
		string str;
		cin >> str;
		if (str == "//") {
			break;
		}
		Object* ob;
		if ((str.size() > 2) and (str[0] == '/') and (str[1] == '/')) {
			ob = root->getUniqueObject(str.substr(2));
		}
		else{
			ob = root->getObject(str);
		} 
		if ((ob == nullptr) or (ob->name != split(str).back())) {
			cout << endl << str << " Object not found";
		}
		else {
			cout << endl << str << " Object name: " << ob->name;
		}
	}
	
	return 0;
}