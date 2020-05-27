#ifndef __OBJ4_H
#define __OBJ4_H
#include "object.h"
#include <string>

using namespace std;

class Object4: public Object {
public:
	Object4(string name, int ready): Object(nullptr, name, ready) {
		this->name = name;
		this->ready = ready;
	}
};
#endif