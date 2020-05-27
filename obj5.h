#ifndef __OBJ5_H
#define __OBJ5_H
#include "object.h"
#include <string>

using namespace std;

class Object5: public Object {
public:
	Object5(string name, int ready): Object(nullptr, name, ready) {
		this->name = name;
		this->ready = ready;
	}
};
#endif