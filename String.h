#ifndef STRING_H
#define STRING_H

#include <cstdlib>
#include <iostream>
#include <vector>

class String {
 public:
  /**
   * @brief default string constructor
   * Creates an empty string
   */
  String();

  /**
   * @brief c-string constructor
   *
   * Creates a string whose contents are the same
   * as initialValue
   *
   * @param initialValue initial value
   */
  String(const char* initialValue);

  /**
   * @brief size string constructor
   *
   * Creates a string whose contents are the
   * first N characters of initialValue
   *
   * Example:
   *
   * String s("Example test", 7); // value store sould be "Example"
   *
   * @param initialValue initial value of the strnig
   * @param n number of characters to copy
   */
  String(const char* initialValue, const int n);

  /**
   * @brief String copy constructor
   *
   * Initializes this string object with a copy
   * of the string held by other
   *
   * Example:
   *
   * String s(String("hello")); // value s is also now "hello"
   */
  String(const String& other);

  /**
   * @brief operator == comparison operator
   *
   * Returns true if the contents of other are the same as this object,
   * false otherwise
   */
  bool operator==(const String& other) const;

  /**
   * @brief operator = assignment operator
   *
   * Assigns to this string the value of other.
   *
   * Example:
   *
   * String s = String("hello"); // value of s is also "hello"
   *
   * NOTE: make sure you copy the string contents and not just
   * the pointer value. Otherwise you will end up
   * with two string objects pointing to the same memory
   * region, and that is not what this method should do
   */
  String& operator=(const String& other);

  /**
   * @brief operator += concatenation operator
   *
   * Concatenates the contents of other into this object.
   *
   * Example:
   *
   * String s("Hello"):
   *
   * s += String(" world"); //contents of s are now "Hello world"
   */
  String& operator+=(const String& other);

  /**
   * @brief size returns the size of this string
   */
  size_t size() const;

  /**
   * @brief clear clears the contents of this string
   *
   * After calling clear(), this object should represent an
   * empty string whose size is 0
   */
  void clear();

  /**
   * @brief tokenize splits the strings into tokens. The
   * separator is passed as an argument
   *
   * Example:
   *
   * String s("Hello world");
   *
   * std::vector<String> tokens = s.tokenize(' ');
   *
   * Contents of tokens are now:
   * { String("Hello"), String("world") }
   */
  std::vector<String> tokenize(const char separator);

  String trim();

  /**
   * @brief ptr returns a pointer to the internal c-string
   *
   * This method is to provide compatibility with the unit testing
   * framework methods who expect a string. This has
   * already been implemented for you.
   */
  const char* ptr() const;

  /**
    * @brief String destructor
    *
    * Make sure you free up any resources (such as meemory)
    * that your string object allocated on construction
    */
  ~String();

 private:
  char* m_str;  // memory where you will store the string
  size_t m_sz;  // size of the string
};

/**
 * @brief operator << output stream operator
 *
 * This is to provide some nice output for the unit tests.
 * This method has already been implemented for you
 */
std::ostream& operator<<(std::ostream&, const String&);

#endif  // STRING_H
