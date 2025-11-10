#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* =========== Template class OrderedList declaration =========== */
template<typename TheType> class OrderedList {
   public:
      int Size();                              // Number of elements in the list
      TheType At(int index);                   // Return the element at index

      int Find(TheType value);                 // Return index of first occurrence
                                               // of value or -1 if not found
      void Insert(TheType value);              // Insert value at its sorted index
      bool Remove(TheType value);              // Find the first occurrence of value
                                               // and remove the value; true if success

      void Print();

   private:
      vector<TheType> list;                    // Elements are stored in list
};

/* =========== OrderedList function implementations =========== */

// Size: Return the number of elements in the list
template<typename TheType>
int OrderedList<TheType>::Size() {
   return list.size();
}

// At: Return the element at a specific index
template<typename TheType>
TheType OrderedList<TheType>::At(int index) {
   return list.at(index);
}

// Find: Search for a value and return its index
// FIXED: Added proper loop variable declaration with semicolon
template<typename TheType>
int OrderedList<TheType>::Find(TheType value) {
   // Loop through each position - note the 'i' variable and semicolons
   for (unsigned int i = 0; i < list.size(); i++) {
      if (list.at(i) == value) {
         return i;  // Found it! Return the position
      }
   }
   return -1;  // Not found
}

// Insert: Add a value while maintaining sorted order
template<typename TheType>
void OrderedList<TheType>::Insert(TheType newItem) {
   unsigned int j;
   unsigned int k;

   if (list.size() == 0) {
      list.push_back(newItem);
      return;
   }

   j = 0;
   while (j < list.size() && newItem > list.at(j)) {
      ++j;
   }

   list.resize(list.size() + 1);

   if (j == list.size()) {
      list.push_back(newItem);
   } else {
      for (k = list.size() - 1; k > j; --k) {
         list.at(k) = list.at(k-1);
      }
      list.at(k) = newItem;
   }
}

// Remove: Find and remove a value from the list
// FIXED: Changed 'index' to 'indx' to match the variable name
template<typename TheType>
bool OrderedList<TheType>::Remove(TheType oldItem) {
   int indx = Find(oldItem);  // Use Find() to locate the item

   // If not found, return false
   if (indx == -1) {
      return false;
   }

   // Found it! Remove using erase()
   // Note: We must cast indx to the correct type for the iterator arithmetic
   list.erase(list.begin() + indx);

   return true;
}

// Print: Display all elements separated by spaces
template<typename TheType>
void OrderedList<TheType>::Print() {
   for (int j = 0; j < Size(); ++j) {
      cout << list.at(j);
      if (j < Size()) {
         cout << " ";
      }
   }
}

/* --------- End OrderedList function implementations ----------- */

// Demonstration of functions
int main() {
   OrderedList<int> intList;
   intList.Insert(11);
   intList.Insert(3);
   intList.Insert(7);

   if (intList.Size() == 3) {
      cout << "Size is correct" << endl;
   }
   else {
      cout << "Size should be 3" << endl;
   }

   if (intList.At(0) == 3 && intList.At(1) == 7 && intList.At(2) == 11) {
      cout << "List is in correct order: ";
   }
   else {
      cout << "List is out of order: ";
   }
   intList.Print();
   cout << endl;

   int indx = intList.Find(11);
   if (indx == 2) {
      cout << "Index of 11 is correct -- " << indx << endl;
   }
   else {
      cout << "Index of 11 is incorrect -- " << indx << endl;
   }

   intList.Remove(7);
   if (intList.At(0) == 3 && intList.At(1) == 11) {
      cout << "7 was removed correctly" << endl;
   }
   else {
      cout << "7 was not removed correctly" << endl;
   }
}