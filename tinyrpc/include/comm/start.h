#ifndef TINYRPC_COMM_START_H
#define TINYRPC_COMM_START_H

#include "comm/log.h"
#include "net/tcp/tcp_server.h"
#include "net/timer.h"
#include <functional>
#include <google/protobuf/service.h>
#include <memory>
#include <stdio.h>

namespace tinyrpc {
#define REGISTER_SERVICE(service)                                                                                                   \
    do {                                                                                                                            \
        if (!tinyrpc::GetServer()->registerService(std::make_shared<service>())) {                                                  \
            printf(                                                                                                                 \
                "Start TinyRPC server error, because register protobuf service error, please look up rpc log get more details!\n"); \
            tinyrpc::Exit(0);                                                                                                       \
        }                                                                                                                           \
    } while (0)

void InitConfig(const char* file);

void StartRpcServer();

TcpServer::ptr GetServer();

int GetIOThreadPoolSize();

Config::ptr GetConfig();

void AddTimerEvent(TimerEvent::ptr event);

}  // namespace tinyrpc

#endif
