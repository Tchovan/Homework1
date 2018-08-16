#include "String.h"
#include <cstring>

String::String() {
  // default constructor
  // size should be zero
  // m_str should hold "" (don't forget c strings end with '\0')
}

String::String(const char* initialValue) {
  // copy the string held by initialValue into m_str
  // and set m_sz to the proper size

  // remember this is a deep copy
}

String::String(const char* initialValue, const int n) {
  // in this constructor you'll copy the first N characters
  // of initialValue into m_str
}

String::String(const String& other) : String(other.ptr()) {
  // this is the copy constructor, which can be invoked
  // by containers such as std::vector and std::map

  // In this case we must define our own, because we need
  // to make sure the new object has its own copy of
  // m_str, rather than pointing to the same reference
  // as "other"

  // I have done this for you by forwarding to the
  // constructor that takes in a char*. You don't
  // need to implement anything else in this method
}

bool String::operator==(const String& o) const {
  // This is the comparison operator for our string object.
  // It should return true if the contents of this object and
  //"other" are the same, and false otherwise
}

String& String::operator=(const String& o) {
  // this method will copy the contents of "o"
  // into this object

  // remember this is a deep copy and not a shallow one

  return *this;
}

String& String::operator+=(const String& o) {
  // this method will concatenate a String object into
  // the contents of m_str. Example:
  // String a("hello");
  // a += String("world");
  // The contents of a are now: helloworld

  // return a reference to this object
  return *this;
}

String String::trim() {
  // return a string object that is a copy of this one,
  // but with all leading and trailing spaces trimmed
}

size_t String::size() const {
  // returns the total size of this string
  return m_sz;
}

void String::clear() {
  // clears this string. Note: you want to revert
  // to a state where size() is 0, and the value of the
  // string is ""
}

const char* String::ptr() const {
  // returns the "raw" pointer to the string this object holds
  // this lets us use other C/C++ functions/classes that work
  // with "C"-style strings
  return m_str;
}

std::vector<String> String::tokenize(const char separator) {
  // split the string into a vector of Strings. Use
  // separator as the tokenizer
}

String::~String() {
  // String destructor. Make sure to not leak memory by
  // freeing the memory that m_str points to
}

std::ostream& operator<<(std::ostream& stream, const String& str) {
  // C++ output operator. This is useful for printing and debugging
  // this method is already implemented for you
  stream << str;
  return stream;
}
