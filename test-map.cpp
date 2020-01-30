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

void test_constructor() {
  Hashmap *map = new Hashmap();
  t_true(map->size() == 0);
  t_true(map->hash() != 0);
  t_true(map->hash_code != 0);
  Hashmap *map2 = new Hashmap();
  t_true(map->equals(map2));
  for (size_t i = 0; i < map->capacity_; i++) {
    // test for method initialize(data)
    t_true(map->data[i] == nullptr);
  }
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
  for (size_t i = 0; i < map->capacity_; i++) {
    t_true((map->data[i] == nullptr) || (map->get(o)->equals(ov)));
  }
  OK("map_advance_method");
}

int main(void) {
  test_constructor();
  test_basic_method();
  test_advance_method();
  return 0;
}
