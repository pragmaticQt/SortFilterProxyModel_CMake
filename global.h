
#ifndef __SHARED_EXPORT_HPP__
#define __SHARED_EXPORT_HPP__

#ifdef WIN32
#    ifdef SFPM_SHARED
#        define SFPM_API_ __declspec(dllexport)
#    elif SFPM_STATIC
#        define SFPM_API_
#    else
#        define SFPM_API_ __declspec(dllimport)
#    endif
#else
#    define SFPM_API_
#endif

#endif
