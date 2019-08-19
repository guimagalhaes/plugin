#ifndef DLIBH_
#define DLIBH_

#include <dlfcn.h>
#include <string>

class dlib
{
    private:
        std::string lib_name;
        void *handle;//construtor de copia e operator=
    
    public:
        //colocar o modo da abertura da biblioteca
        explicit dlib(const std::string &lib);
        dlib();
        virtual ~dlib();
    
        //set lib name
        void set_lib_name(const std::string &s) { lib_name = s; }
        
        //return dl handle
        void *get_handle() { return handle; }
        
        //load library
        //returns zero on success, -1 otherwise
        int load_lib();
        //close library
        //return zero on success, non-zero otherwise
        int close_lib();
        
        //call function
        //return NULL on error, otherwise return what
        //the function returns
        void *get_f(const std::string &function_name);
};

#endif
