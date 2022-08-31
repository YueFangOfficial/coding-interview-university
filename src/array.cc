#include <stdio.h>
#include <cstdlib>

// mutable array with automatic resizing
class MyVector {
  // how to store any type?
 public:
  struct vector {
    int* array;
    int vec_size;
    int vec_capacity;
  } v; // need to allocate one

  // default contor
  MyVector();
  ~MyVector();
  int size();      // - number of items
  int capacity();  // - number of items it can hold
  bool is_empty();
  // TODO: any type for at(), item, pop()
  int at(int index);  // - returns item at given index, blows up if index out of
                      // bounds
  void push(int item);
  void insert(int index,
              int item);        // - inserts item at index, shifts that index's
                                // value and trailing elements to the right
  void prepend(int item);       // - can use insert above at index 0
  int pop();                    // - remove from end, return value
  void delete_item(int index);  // - delete item at index, shifting all trailing
                                // elements left
  void remove(int item);  // - looks for value and removes index holding it
                          // (even if in multiple places)
  int find(int item);  // - looks for value and returns first index with that
                       // value, -1 if not found
 private:
  void resize(int new_capacity);  // private function
  // when you reach capacity, resize to double the size
  // when popping an item, if size is 1/4 of capacity, resize to half
};

MyVector::MyVector() {
  v.vec_capacity = 16;
  v.vec_size = 0;
  v.array = (int*)malloc(v.vec_capacity * sizeof(int));
}

MyVector::~MyVector() {
  free(v.array);
}

// number of items
int MyVector::size() { return v.vec_size; }
// - number of items it can hold
int MyVector::capacity() { return v.vec_capacity; }
bool MyVector::is_empty() { return (v.vec_size == 0); }
// - returns item at given index, blows up if index out of bounds
int at(int index) {}
void MyVector::push(int item) {}
// - inserts item at index, shifts that index's value and trailing elements to
// the right
void MyVector::insert(int index, int item) {}
// - can use insert above at index 0
void MyVector::prepend(int item) {}
// - remove from end, return value
// pop();
// - delete item at index, shifting all trailing elements left
void MyVector::delete_item(int index) {}
// - looks for value and removes index holding it (even if in multiple places)
void MyVector::remove(int item) {}
// - looks for value and returns first index with that value, -1 if not found
int MyVector::find(int item) {}
void MyVector::resize(int new_capacity) { v.vec_capacity = new_capacity; }

int main() {
  MyVector mv;
  return 0;
}
/* [ ] Implement a vector (mutable array with automatic resizing):
[ ] Practice coding using arrays and pointers, and pointer math to jump to an
index instead of using indexing.
[ ] New raw data array with allocated memory
[] can allocate int array under the hood, just not use its features
[] start with 16, or if starting number is greater, use power of 2 - 16, 32, 64,
128 [ ] Time
[] O(1) to add/remove at end (amortized for allocations for more space), index,
or update
[] O(n) to insert/remove elsewhere
[ ] Space
[] contiguous in memory, so proximity helps performance
[] space needed = (array capacity, which is >= n) * size of item, but even if
2n, still O(n) */