#include "dlib.h"
#include "direxp.h"

#include <iostream>

using namespace std;

typedef int (*init_mod_t)();

void todo_files(const char* v)
{
    const char *lib_name = static_cast<const char *> (v);
    
    dlib dl(lib_name);
    init_mod_t f = (init_mod_t) dl.get_f("init_mod");
    
    if (f)
        f();
    else
        cout << "init_mod failed for: " << lib_name << endl;
}

int main(int argc, char **argv) {
    direxp dir;
    string pathname = dir.get_pwd() + "/modules/";
    
    dir.dir_explorer(pathname,todo_files);
    
    return 0;
}
