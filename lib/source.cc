#pragma once

#include <filesystem>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::thread;
using std::vector;
namespace os = std::filesystem;

// #define MAX_THREADS 8
// cross-platform default root
#ifdef __linux__
#define DEF_ROOT "/"
#elif _WIN32
#define DEF_ROOT "C:\\"
#else
#define DEF_ROOT "/"
#endif

// finds files
class Locator
{
private:
    string name;
    vector<thread *> threads;

public:
    Locator(string name) : name(name) {}
    ~Locator() {}

    // recursive method to find file in dir, it generates thread for evry subdit
    void find_in_dir(os::directory_iterator root)
    {
        for (auto &file : root)
        {
            if (file.is_directory())
            {
                // new thread for this method and iterator which skips permission denied files and dirs
                thread *t = new thread(&Locator::find_in_dir, this, os::directory_iterator(file.path(), os::directory_options::skip_permission_denied));
                threads.push_back(t);
            }
            // in case of success
            else if (file.path().filename() == name)
            {
                cout << file.path() << endl;
                return;
            }
        }
    }

    void run(string root)
    {
        find_in_dir(os::directory_iterator(root, os::directory_options::skip_permission_denied));
        // closing all threades
        for (int i = 0; i < threads.size(); i++)
            threads[i]->join();
    }

    string getName() const& { return name; }
    void setName(const string &name_) { name = name_; }
};
