#ifndef TINYRPC_COMM_CONFIG_H
#define TINYRPC_COMM_CONFIG_H

#include <map>
#include <memory>
#include <string>

#ifdef DECLARE_MYSQL_PLUGIN
#include "tinyrpc/comm/mysql_instase.h"
#endif

namespace tinyrpc {

enum LogLevel {
    DEBUG = 1,
    INFO  = 2,
    WARN  = 3,
    ERROR = 4,
    NONE  = 5  // don't print log
};

class Config {};

}  // namespace tinyrpc

#endif  // TINYRPC_COMM_CONFIG_H
