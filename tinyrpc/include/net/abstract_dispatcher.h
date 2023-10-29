#ifndef TINYRPC_NET_ABSTRACT_DISPATCHER_H
#define TINYRPC_NET_ABSTRACT_DISPATCHER_H

#include "net/abstract_data.h"
#include "net/tcp/tcp_connection.h"
#include <google/protobuf/service.h>
#include <memory>

namespace tinyrpc {

class TcpConnection;

class AbstractDispatcher {
public:
    typedef std::shared_ptr<AbstractDispatcher> ptr;

    AbstractDispatcher() {}

    virtual ~AbstractDispatcher() {}

    virtual void dispatch(AbstractData* data, TcpConnection* conn) = 0;
};

}  // namespace tinyrpc

#endif
