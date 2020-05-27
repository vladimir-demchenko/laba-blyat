#ifndef __OBJ2_H
#define __OBJ2_H
#include "object.h"
#include <string>

using namespace std;

class Object2: public Object {
public:
	Object2(string name, int ready): Object(nullptr, name, ready) {
		this->name = name;
		this->ready = ready;
	}
};
#endif