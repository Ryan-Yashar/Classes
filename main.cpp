#include <Common.h>
#include <Media.h>

using namespace std;


void addCommand(vector<Media*>& media_list) {
  char input[8];
  cout << "Enter the type of media you'd like to add. Valid types include Game, Movie, and Song. Input: ";
  cin.get(input, 8);
  while (cin.get() != '\n') {}
  for (int i=0; input[i] != '\0'; i++) {
    if ('a' <= input[i] && 'z' >= input[i]) {
      input[i] -= 32; //capitalize everything
    }
  }
  if (!strcmp(input, "GAME")) {
    
  } else if (!strcmp(input, "MOVIE")) {
    searchCommand(media_list);
  } else if (!strcmp(input, "SONG")) {
    deleteCommand(media_list);
  } else {
    cout << "Type \"" << input << "\" not found. Try again.\n";
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
