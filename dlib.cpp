#include "dlib.h"
#ifdef DEBUG
#include <iostream>
#endif

using namespace std;

dlib::dlib(const std::string &lib): lib_name(lib) 
{
    load_lib();
}

dlib::dlib()
{
}

dlib::~dlib()
{
    close_lib();
}

int dlib::load_lib()
{
    handle = dlopen (lib_name.c_str(), RTLD_LAZY);
    if (!handle) {
#ifdef DEBUG
      cerr << dlerror() << endl;
#endif
      return -1;
    }
    
    return 0;
}

int  dlib::close_lib()
{
    return dlclose(handle);
}

void *dlib::get_f(const std::string &function_name)
{
    char *error;
    void *f;
    
    f = dlsym(handle, function_name.c_str());
    if ((error = dlerror()) != NULL)  {
#ifdef DEBUG
        cerr << error << endl;
#endif
        return NULL; 
    }

    return f;
}
