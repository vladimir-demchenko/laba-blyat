#ifndef __OBJ1_H
#define __OBJ1_H
#include "object.h"
#include <string>

using namespace std;

class Object1: public Object {
public:
	Object1(string name, int ready): Object(nullptr, name, ready) {
		this->name = name;
		this->ready = ready;
	}
};
#endif