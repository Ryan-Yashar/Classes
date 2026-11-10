#include "Common.h"
#include "Media.h"
#include "Games.h"
#include "Movies.h"
#include "Music.h"
#include "Helpers.h"

void addCommand(vector<Media*>& media_list) {
  char input[8];
  char type[6];
  while (true) {
    cout << "Enter the type of media you'd like to add. Valid types include Game, Movie, and Song. Input: ";
    get(input, 8);
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
  prompt(title, type, "title", 0);
  int year;
  char yearinput[51];
  prompt(yearinput, type, "year", 1);
  year = stoi(yearinput);
  char publisher[51];
  char director[51];
  if (strcmp(type, "movie")) {
    prompt(publisher, type, "publisher", 0);
  } else {
    prompt(director, type, "director", 0);
  }
  int duration;
  char durationinput[51];
  if (strcmp(type, "game")) {
    prompt(durationinput, type, "duration", 1);
    duration = stoi(durationinput);
  }
  char ratinginput[51];
  float rating;
  char artist[51];
  if (strcmp(type, "song")) {
    prompt(ratinginput, type, "rating", 2);
    rating = stof(ratinginput);
  } else {
    prompt(artist, type, "artist", 0);
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
void deleteCommand(vector<Media*>& media_list) {
}
int main() {
  vector<Media*> media_list;
  char input[8];
  cout << fixed << setprecision(2); //print floats to 2 decimals
  while (true) {
    cout << "Enter one of ADD, SEARCH, DELETE, QUIT to continue. ADD prompts for a new media item, SEARCH lets you search for items via title or year, DELETE deletes one media item from the list, and QUIT ends program execution. Input: ";
    get(input, 8);
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
