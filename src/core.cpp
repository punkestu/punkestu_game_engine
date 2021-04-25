#include "core.h"

void warning(std::string reason, std::string warn){
    printf("warning[%s]: %s", reason.c_str(), warn.c_str());
}

void error(std::string reason, std::string err){
    printf("error[%s]: %s", reason.c_str(), err.c_str());
}