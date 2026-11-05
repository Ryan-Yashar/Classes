#include <Media.h>

class Media {
  protected:
    char title[51];
    int year;
  public:
    Media(const char* title, int year) : year(year) {
      strncpy(this->title, title, 50);
      (this->title)[50] = '\0';
    }
    int getYear() {
      return this->year;
    }
    const char* getTitle() {
      return this->title;
    }
    virtual ~Media() = default;
};
