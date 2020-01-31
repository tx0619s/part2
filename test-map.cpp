#include "map.h"
#include "object.h"
#include "string.h"

void FAIL() { exit(1); }
void OK(const char *m) { printf("test %s passed\n", m); }
void t_true(bool p) {
  if (!p)
    FAIL();
}
void t_false(bool p) {
  if (p)
    FAIL();
}
String *cast_string(Object *object) { return dynamic_cast<String *>(object); }
bool list_contains(Object** list, Object *object, size_t size) {
  for (size_t i = 0; i < size; i++) {
    if (list[i]) {
      if (list[i]->equals(object)) {
        return true;
      }
    }
  }
  return false;
}

String *a = new String("key_1");
String *b = new String("key_2");
String *c = new String("key_3");
String *d = new String("key_4");
String *av = new String("val_1");
String *bv = new String("val_2");
String *cv = new String("val_3");
String *dv = new String("val_4");
Object *o = new Object();
Object *ov = new Object();

void string_test() {
  String *s = new String("Hello");
  String *t = new String("World");
  String *u = s->concat(t);
  t_true(s->equals(s));
  t_false(s->equals(t));
  t_false(s->equals(u));
  OK("string_test");
}

void object_test() {
  Object *o1 = new Object();
  Object *o2 = new Object();
  t_false(o1->equals(o2));
  t_true(o1->equals(o1));
  t_true(o2->equals(o2));
  OK("Object_test");
}

void string_advance_test() {
  String *s = new String("Hello");
  String *t = new String("World");
  String *u = s->concat(t);
  t_true(s->hash() == u->hash());
  t_false(s->hash() == t->hash());
  OK("string_advance_test");
}

void test_constructor() {
  Hashmap *map = new Hashmap();
  t_true(map->size() == 0);
  t_true(map->hash() != 0);
  Hashmap *map2 = new Hashmap();
  t_true(map->equals(map2));
  t_true(map->hash() == map2->hash());
  map->put(a, av);
  map->put(b, bv);
  t_false(map->hash() == map2->hash());
  OK("map_constructor");
}

void test_basic_method() {
  Hashmap *map = new Hashmap();
  map->put(a, av);
  map->put(b, bv);
  map->put(c, cv);
  map->put(d, dv);
  t_true(map->size() == 4);
  t_true(map->capacity_ >= 4);
  map->remove(a);
  t_true(map->size() == 3);
  size_t size_before_expand = map->capacity_;
  map->expand();
  t_true(map->capacity_ == 2 * size_before_expand);
  OK("map_basic_method");
}

void test_advance_method() {
  Hashmap *map = new Hashmap();
  map->put(a, av);
  map->put(b, bv);
  map->put(c, cv);
  map->put(d, dv);
  map->put(o, ov);
  t_true(map->size() == 5);
  map->put(a, ov);
  t_true(map->size() == 5);
  Object** keys = map->key_array();
  t_true(list_contains(keys, a, map->size_));
  t_true(list_contains(keys, b, map->size_));
  t_true(list_contains(keys, c, map->size_));
  t_true(list_contains(keys, d, map->size_));
  t_true(list_contains(keys, o, map->size_));
  OK("map_advance_method");
}

int main(void) {
  object_test();
  string_test();
  string_advance_test();
  test_constructor();
  test_basic_method();
  test_advance_method();
  return 0;
}
