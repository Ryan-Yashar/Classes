#include "Common.h"
#include "Media.h"

using namespace std;

bool verifyCorrect(char* valuetoprint) {
  while (true) {
    char correct;
    while (correct != 'y' && correct != 'n') {
      cout << "Is \"" << valuetoprint << "\" correct? (y/n)";
      cin.get(correct);
      while (cin.get() != '\n') {}
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
void addCommand(vector<Media*>& media_list) {
  char input[8];
  char type[6];
  while (true) {
    cout << "Enter the type of media you'd like to add. Valid types include Game, Movie, and Song. Input: ";
    cin.get(input, 8);
    while (cin.get() != '\n') {}
    for (int i=0; input[i] != '\0'; i++) {
      if ('a' <= input[i] && 'z' >= input[i]) {
        input[i] -= 32; //capitalize everything
      }
    }
    if (!strcmp(input, "GAME")) {
      strncpy(type, "game\0", 6);
      break;
    } else if (!strcmp(input, "MOVIE")) {
      strncpy(type, "movie\0", 6);
      break;
    } else if (!strcmp(input, "SONG")) {
      strncpy(type, "song\0", 6);
      break;
    } else {
      cout << "Type \"" << input << "\" not found. Try again.\n";
    }
  }
  char title[51];
  while (true) {
    cout << "Enter the title of the " << type << ": ";
    cin.get(title, 51);
    while (cin.get() != '\n') {}
    if (verifyCorrect(title)) {
      break;
    }
  }
  int year;
  char yearinput[51];
  while (true) {
    cout << "Enter the year the " << type << " was made: ";
    cin.get(yearinput, 51);
    while (cin.get() != '\n') {}
    if (numType(yearinput) != 1) {
      cout << "Error - year must be a positive integer. Try again.\n";
      continue;
    }
    if (verifyCorrect(yearinput)) {
      year = stoi(yearinput);
      break;
    }
  }
  char publisher[51];
  char director[51];
  if (strcmp(type, "movie")) {
    while (true) {
      cout << "Enter the publisher of the " << type << ": ";
      cin.get(publisher, 51);
      while (cin.get() != '\n') {}
      if (verifyCorrect(publisher)) {
        break;
      }
    }
  } else {
    while (true) {
      cout << "Enter the director of the " << type << ": ";
      cin.get(director, 51);
      while (cin.get() != '\n') {}
      if (verifyCorrect(director)) {
        break;
      }
    }
  }
  int duration;
  char durationinput[51];
  if (strcmp(type, "game")) {
    while (true) {
      cout << "Enter the duration of the " << type << ": ";
      cin.get(durationinput, 51);
      while (cin.get() != '\n') {}
      if (numType(durationinput) != 1) {
        cout << "Error - duration must be a positive integer. Try again.\n";
        continue;
      }
      if (verifyCorrect(durationinput)) {
        duration = stoi(durationinput);
        break;
      }
    }
  }
  char ratinginput[51];
  float rating;
  char artist[51];
  if (strcmp(type, "song")) {
    while (true) {
      cout << "Enter the rating of the " << type << ": ";
      cin.get(ratinginput, 51);
      while (cin.get() != '\n') {}
      if (numType(ratinginput) == 0) {
        cout << "Error - duration must be a positive float. Try again.\n";
        continue;
      }
      if (verifyCorrect(ratinginput)) {
        rating = stof(ratinginput);
        break;
      }
    }
  } else {
    while (true) {
      cout << "Enter the artist of the " << type << ": ";
      cin.get(artist, 51);
      while (cin.get() != '\n') {}
      if (verifyCorrect(artist)) {
        break;
      }
    }
  }
  //end info get
  if (!strcmp(type, "movie")) {
    media_list.push_back(new Movie(title, director, year, duration, rating));
  } else if (!strcmp(type, "song")) {
    media_list.push_back(new Song(title, artist, year, duration, publisher));
  } else {
    media_list.push_back(new Game(title, year, publisher, rating));
  }
}
void searchCommand(vector<Media*>& media_list) {
}
void delete_command(vector<Media*>& media_list) {
}
int main() {
  vector<media> media_list;
  char input[8];
  cout << fixed << setprecision(2); //print floats to 2 decimals
  while (true) {
    cout << "Enter one of ADD, SEARCH, DELETE, QUIT to continue. ADD prompts for a new media item, SEARCH lets you search for items via title or year, DELETE deletes one media item from the list, and QUIT ends program execution. Input: ";
    cin.get(input, 8);
    while (cin.get() != '\n') {}
    for (int i=0; input[i] != '\0'; i++) {
      if ('a' <= input[i] && 'z' >= input[i]) {
        input[i] -= 32; //capitalize everything
      }
    }
    if (!strcmp(input, "ADD")) {
      addCommand(media_list);
    } else if (!strcmp(input, "SEARCH")) {
      searchCommand(media_list);
    } else if (!strcmp(input, "DELETE")) {
      deleteCommand(media_list);
    } else if (!strcmp(input, "QUIT")) {
      cout << "Quitting...\n";
      break;
    } else {
      cout << "Command \"" << input << "\" not found. Try again.\n";
    }
  }
  return 0;
}
