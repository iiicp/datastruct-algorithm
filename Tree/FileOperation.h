/**********************************
 * File:     FileOperation.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/1/12
 ***********************************/

#ifndef BST_FILEOPERATION_H
#define BST_FILEOPERATION_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class FileOperation {
public:
  static bool isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
  }

  static bool isNumber(char c) {
    return c >= '0' && c <= '9';
  }

  static bool readFile(string filename, vector<string>& words) {

    if (filename.size() == 0) {
      std::cout << "filename is null" << std::endl;
      return false;
    }

    ifstream fin;
    fin.open(filename);
    if (fin.fail()) {
      std::cout << "open " << filename << " failed" << std::endl;
      return false;
    }

    char c;
    string word;
    while (fin.get(c)) {
      if (isAlpha(c) || isNumber(c)) {
        word += tolower(c);
      }else {
        if (word.size() > 0) {
          words.push_back(word);
          word.clear();
        }
      }
    }
    if (fin.is_open())
      fin.close();
    return true;
  }
};

#endif // BST_FILEOPERATION_H
