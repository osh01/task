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

#define MAX_THREADS 8
string name = "name";

#ifdef __linux__
// linux code goes here
#elif _WIN32
// windows code goes here
#else

#endif
/*
int count_threads()
{
    int i = 0;
    for (i; i < MAX_THREADS; i++)
        if (slots[i] != NULL)
            i++;
    return i;
}
*/
/*
string check_this_directory(os::directory_iterator dir)
{

    for (auto &file : dir)
    {
        if (file.is_directory())
        {
            if (thread_counter < 8)
            {
                thread_counter++;
                thread t{check_this_directory, file};
            }
        }
        if (file.path().filename() == name)
        {
            cout << file.path() << ": succes" << endl;
            return "";
        }
        else
        {
            cout << file << endl;
        }
    }
    thread_counter--;
}
*/

#include <list>

int main()
{
    std::list<os::directory_iterator> todo;
    todo.push_back(os::directory_iterator("/home/evgen"));

    vector<thread *> workers;

    int c = 1;
    for (auto i = todo.begin(); i != todo.end(); i++)
    {
        /* code */
    }

    while (!todo.empty())
    {
        int c = 0;
        while (!todo.empty() && c < 8)
        {
            auto current = todo.front(); todo.pop_front();
            for (auto &file : current)
            {
                if (file.is_directory())
                    todo.push_back(current);
                else if (file.path().filename() == name)
                {
                    cout << file.path() << ": succes" << endl;
                    return 0;
                }
                else
                {
                    cout << file.path() << endl;
                }
            }
            c++;
        }
    }

    auto current = todo.front();
    todo.pop_front();
    for (auto &file : current)
    {
        if (file.is_directory())
            todo.push_back(current);
        else if (file.path().filename() == name)
        {
            cout << file.path() << ": succes" << endl;
            return 0;
        }
        else
        {
            cout << file.path() << endl;
        }
    }
    // out

    return 0;
}