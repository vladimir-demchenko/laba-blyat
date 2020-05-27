#ifndef __OBJ3_H
#define __OBJ3_H
#include "object.h"
#include <string>

using namespace std;

class Object3: public Object {
public:
	Object3(string name, int ready): Object(nullptr, name, ready) {
		this->name = name;
		this->ready = ready;
	}
};
#endif