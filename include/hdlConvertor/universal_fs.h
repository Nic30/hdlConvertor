#pragma once

#if (defined(__GNUC__) && __GNUC__ < 8)
#include <experimental/filesystem>
namespace std {
    namespace filesystem = experimental::filesystem;
}
#else
#include <filesystem>
#endif
