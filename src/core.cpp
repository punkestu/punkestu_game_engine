#include "core.h"

void warning(std::string reason, std::string warn){
    printf("warning[%s]: %s", reason, warn);
}

void error(std::string reason, std::string err){
    printf("error[%s]: %s", reason, err);
}