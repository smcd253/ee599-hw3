#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>

class Solution {
public:

  /**
   * Add overload 1.
   * 
   * @param   a                              <tt>int</tt> to add.
   * @param   b                              <tt>int</tt> to add.
   * 
   * @returns <tt>int</tt> a + b             On success.
   * 
   * */
  int add(int a, int b);

  /**
   * Add overload 2.
   * 
   * @param   a                              <tt>string</tt> to append to.
   * @param   b                              <tt>string</tt> to append.
   * 
   * @returns <tt>string</tt> "ab"          On success.
   * 
   * */
  std::string add(std::string& a, std::string& b);

  /**
   * Add overload 3.
   * 
   * @param   a                              <tt>string</tt> to append to.
   * @param   b                              <tt>int</tt> to convert to string,
   *                                         then append.
   * 
   * @returns <tt>string</tt> "ab"          On success.
   * 
   * */
  std::string add(std::string& a, int b);

   /**
   * Add overload 4.
   * 
   * @param   a                              <tt>int</tt> to convert to string, 
   *                                         then append to.
   * @param   b                              <tt>string</tt> to append.
   * 
   * @returns <tt>string</tt> "ab"          On success.
   * 
   * */
  std::string add(int a, std::string& b);
};

#endif