#include "Helpers.h"

//gets string of n size from cin without blowing things up
void get(char* buffer, size_t size) {
  cin.get(buffer, size);
  cin.clear();
  while (cin.get() != '\n') {}
}
bool verifyCorrect(char* valuetoprint) {
  while (true) {
    char correct;
    while (correct != 'y' && correct != 'n') {
      cout << "Is \"" << valuetoprint << "\" correct? (y/n)";
      cin.get(correct);
      if (correct != '\n') {
        while (cin.get() != '\n') {}
      }
      if (correct == 'y') {
        return true;
      } else if (correct == 'n') {
        cout << "Retrying...\n";
        return false;
      } else {
        cout << "You must enter y or n.\n";
      }
    }
  }
}
//determines whether a value is positive int, positive float, or neither
int numType(char* input) {
  int dotcount = 0;
  for (int i=0; input[i]!='\0'; i++) {
    //is the input a numerical value
    if (!('0' <= input[i] && '9' >= input[i])) {
      //is it a dot
      if (input[i] == '.') {
        dotcount += 1;
      } else {
        return 0; //neither int nor float
      }
    }
  }
  if (dotcount == 0) {
    return 1; //int
  } else if (dotcount == 1) {
    return 2; //is float
  } else {
    return 0; //neither int nor float
  }
}
//input is where answer is sent, type is the type of media, attribute is the attribute of the item, allowedTypes is 0 if string, 1 if int, 2 if float
void prompt(char* input, const char* type, const char* attribute, int allowedTypes) {
  while (true) {
    cout << "Enter the " << attribute << " of the " << type << ": ";
    get(input, 51);
    if (allowedTypes == 1) {
      if (numType(input) != 1) {
        cout << "Error - " << attribute << " must be a positive integer. Try again.\n";
        continue;
      }
    } else if (allowedTypes == 2) {
      if (numType(input) == 0) {
        cout << "Error - " << attribute << " must be a positive float. Try again.\n";
        continue;
      }
    }
    if (verifyCorrect(input)) {
      break;
    }
  }
}