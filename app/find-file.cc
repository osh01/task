#include "../lib/source.cc"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    string root = DEF_ROOT, name = "";

    Locator finder(name);

    for (int i = 1; i < argc; i++)
    {
        const std::string arg = argv[i];
        if (arg == "-h" || arg == "--help") // help
        {
            std::cout << " Usage: find-file [-h/--help] file_to_find\n";
            return 0;
        }
        if (arg == "-r" || arg == "--root") // setting root, Locator will start search from this dir
        {
            if (argv[i + 1])
            {
                root = argv[i + 1];
                i++;
            }
            else
            {
                std::cout << "Omited root!\n";
                return 0;
            }
        }
        else // the other unqualified arguments are treated like target to find
            finder.setName(arg);
    }

    // run
    finder.run(root);

    return 0;
}