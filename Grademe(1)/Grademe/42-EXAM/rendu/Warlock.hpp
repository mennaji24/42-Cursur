#include <iostream.h>

class Warlock{

private:

    std::string name;
    std::string title;
    Warlock();


public:

    std::string *getName();
    std::string *getTitle();
    std::string setTitle();

}
