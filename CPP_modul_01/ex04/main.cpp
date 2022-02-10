#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

void    checkArgs(int ac,char **av)
{
    if (ac != 4)
    {
        std::cout << "Error: bad arguments, try again!\n";
        exit(1);
    }
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    if (filename.empty() || s1.empty() || s2.empty())
    {
        std::cout << "Error: bad arguments, try again!\n";
        exit(1);  
    }
}

int main(int ac, char **av)
{
    std::ifstream       file_in;
    std::ofstream       file_out;
    std::stringstream   buffer;
    std::string         str;
    std::string         new_filename;
    std::size_t         index;

    checkArgs(ac, av);
    file_in.open(av[1], std::ios::in);
    if (!file_in.good())
    {
        std::cout << "Error: " << strerror(errno) << std::endl;
        exit(1);
    }
    if (file_in.peek() == EOF)
    {
        std::cout << "Error: empty file, try again!\n";
        exit(1);       
    }
    buffer << file_in.rdbuf();
    str = buffer.str();
    new_filename = av[1];
    new_filename += ".replace";
    file_out.open(new_filename);
    if (!file_out.good())
    {
        std::cout << "Error: " << strerror(errno) << std::endl;
        exit(1);
    }
    index = 0;
    while ((index = str.find(av[2], index)) != std::string::npos && strcmp(av[2], av[3]))
    {
        str.erase(index, strlen(av[2]));
        str.insert(index, av[3]);
    }
    file_out << str;
    file_in.close();
    file_out.close();
    return 0;
}