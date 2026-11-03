#include <stdio>
#include <cstring>

using namespace std;

class Media {
  protected:
    char title[51];
    int year;
  public:
    Media(const char* title, int year) : year(year) {
      strncpy(this->title, title, 50);
      (this->title)[50] = '\0';
    }
    ~Media() = default;
};
class Games : public Media {
  protected:
    char publisher[51];
    long rating;
  public:
    Games(const char* title, int year, const char* publisher, long rating) : Media(title, year), rating(rating) {
      strncpy(this->publisher, publisher, 50);
      (this->publisher)[50] = '\0';
    }
    ~Games() = default;
};

int main() {
  return 0;
}
