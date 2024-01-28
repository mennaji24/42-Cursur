#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

int main(int argc, char **argv)
{
    if(argc < 2){
        std::cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int j = 1; j < argc; j++)
    {
        for (size_t i = 0; i < strlen(argv[j]); ++i) {
             std::cout << (char)(toupper(argv[j][i]));
        }

    }
    std::cout << std::endl;

    return 0;
}