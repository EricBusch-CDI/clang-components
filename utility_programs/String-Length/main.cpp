#include <iostream>
#include <string>
int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        std::cout << "Enter a string as a command" << std::endl;
        return -1;
    }
    else
    {
        unsigned int total_length = 0;
        for(int i = 1; i < argc; i++)
        {
            std::string str(argv[i]);

            total_length += str.length();
            if(i + 1 < argc)
            {
                total_length += 1; // add one for space
            }
        }
        std::cout << "String Length: " << total_length << std::endl;
    }
    return 0;
}