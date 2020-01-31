The implementation of the map takes each key-value pair element in the map 
as a Hashmap-pair. Both Hashmap and Hashmap_pair inherit Object class.


Hashmap_pair Class:

The Hashmap_pair class has been implemented to hold a key-value pair. We 
will can use each of these pairs to create whatever structure we would 
like. Note that the type of key and value are objects.


Hashmap Class:

Hashmap class is in the same header file with Hashmap_pair class. It has 
size, capacity, and list of Hashmap_pair as fields. 

Some basic functions are to be implemented:

  // hash and return unique hashcode. two hashmaps with 
  // same hashmap_pairs should have the same hashcode.
  size_t hash();
  
  // Double the capacity of hashmap when needed
  void expand();

  // Returns the value to which the specified key is mapped,
  // or null if this map contains no mapping for the key.
  Object *get(Object *key);

  // Associates the specified value with the specified key in this map.
  void put(Object *key, Object *val);

  // Removes the mapping for the specified key from this map if present.
  void remove(Object *key);

  // Returns the number of key-value mappings in this map.
  size_t size();

  // Returns a list view of the keys contained in this map.
  Object **key_array();

  // Check if two Hashmaps are equal.
  // the input hashmap is an object.
  bool equals(Object *map);
