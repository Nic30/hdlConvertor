#pragma once
#include <string>
/*
 * path std namespace to have std::filesystem if required for older compilers
 * */

#if (defined(__GNUC__) && __GNUC__ < 8)
#include <experimental/filesystem>
namespace std {
    namespace filesystem = experimental::filesystem;
}
#else
#include <filesystem>
#endif

// the filename which is used if the code comes from string and not from file
extern const std::string STRING_FILENAME;
