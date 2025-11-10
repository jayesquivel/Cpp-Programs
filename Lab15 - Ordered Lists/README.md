# Lab 15 - Ordered Lists

## Overview
An OrderedList is a vector that keeps elements in sorted order.

## Your Task
Complete `template <typename TheType> class OrderedList` by defining the following functions:

---

### Required Functions to Implement

#### `int Size()`
- **Purpose:** Return the size of the list

#### `TheType At(int index)`
- **Purpose:** Return the element of the list at parameter `index`

#### `int Find(TheType value)`
- **Purpose:** Return the index of the first element in the list equal to parameter `value`
- **Return:** `-1` if parameter `value` is not found in the list

#### `bool Remove(TheType value)`
- **Purpose:** Search the list for parameter `value`
- **Hint:** Use `Find()`
- **Behavior:**
  - If parameter `value` is found in the list:
    - Remove the element by moving subsequent elements towards the beginning
    - Decrement list size
    - Return `true`
  - If not found, return `false`
- **Hint:** Use any vector functions to simplify the implementations

---

### Pre-Implemented Functions
The template code provides implementations of:

#### `void Insert(TheType value)`
- Search the list for an element greater than parameter `value`
- If found:
  - Increment list size
  - Move the element and all subsequent elements towards the end
  - Copy parameter `value` at the location of the first element greater than it
- If not found:
  - Increment list size
  - Add parameter `value` at the end of the list

#### `void Print()`
- Output the list, separated by space characters

---

## Testing

A main program is provided as a sample test in develop mode. Unit tests will be used during submission.

### Example Output
If the given `main()` is executed: