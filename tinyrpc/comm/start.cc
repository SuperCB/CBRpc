#include "comm/start.h"
#include "comm/config.h"
#include "comm/log.h"
#include "coroutine/coroutine_hook.h"
#include "net/tcp/tcp_server.h"
#include <google/protobuf/service.h>

namespace tinyrpc {

tinyrpc::Config::ptr    gRpcConfig;
tinyrpc::Logger::ptr    gRpcLogger;
tinyrpc::TcpServer::ptr gRpcServer;

static int g_init_config = 0;

void InitConfig(const char* file)
{
    tinyrpc::SetHook(false);

    tinyrpc::SetHook(true);

    if (g_init_config == 0) {
        gRpcConfig = std::make_shared<tinyrpc::Config>(file);
        gRpcConfig->readConf();
        g_init_config = 1;
    }
}

TcpServer::ptr GetServer()
{
    return gRpcServer;
}

void StartRpcServer()
{
    gRpcLogger->start();
    gRpcServer->start();
}

int GetIOThreadPoolSize()
{
    return gRpcServer->getIOThreadPool()->getIOThreadPoolSize();
}

Config::ptr GetConfig()
{
    return gRpcConfig;
}

void AddTimerEvent(TimerEvent::ptr event) {}

}  // namespace tinyrpc
