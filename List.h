#ifndef LIST_H
#define LIST_H

class Node {
 public:
  Node(int value);
  ~Node();
  int getValue();
  Node* getNext();
  void setNext(Node* next);
  Node* getPrev();
  void setPrev(Node* prev);

 private:
  Node* m_next;
  Node* m_prev;
  int m_value;
};

class List {
 public:
  List();
  ~List();

  /**
   * @brief add appends an element to the end of the list
   * @param x element to append
   */
  void add(int x);

  /**
   * @brief remove removes an element from the list
   * @param index index of the element to remove
   * @throws std::runtime_error if the index does not exist
   */
  void remove(int index);

  /**
   * @brief returns the value of an element in the list
   * @param index index of the element to query
   * @throws std::runtime_error if the index does not exist
   */
  int get(int index);

  /**
   * @brief insert inserts an element at given position
   * @param val value to insert
   * @param index position to insert at
   *
   * Example:
   *
   * List l;
   * l.add(1);
   * l.add(3);
   *"
   * l.insert(2, 1); //contents of l should now be: 1,2,3
   *
   * @throws std::runtime_error if the index is not valid. For example
   * this is not a valid insertion:
   *
   * List l;
   * l.add(1);
   * l.insert(2,1); //this should throw an exception since there is no index
   *"1", only "0"
   */
  void insert(int val, int index);

  /**
   * @brief count returns the number of elements in the list
   * @return size of the list
   */
  int count();

 private:
  Node* m_head;
  Node* m_tail;
};

#endif
