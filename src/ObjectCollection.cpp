#include "ObjectCollection.h"

void ObjectCollection::add(Object *o) {
   collection.push_back(o);
}

int ObjectCollection::size() {
   return collection.size();
}

Object* ObjectCollection::get(int index) {
   return collection[index];
}
