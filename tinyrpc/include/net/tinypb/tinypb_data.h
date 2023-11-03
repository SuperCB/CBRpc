#pragma once
#include "comm/log.h"
#include "net/abstract_data.h"
#include <stdint.h>
#include <string>
#include <vector>

namespace tinyrpc {

class TinyPbStruct: public AbstractData {
public:
    typedef std::shared_ptr<TinyPbStruct> pb_ptr;
    TinyPbStruct()                               = default;
    ~TinyPbStruct()                              = default;
    TinyPbStruct(const TinyPbStruct&)            = default;
    TinyPbStruct& operator=(const TinyPbStruct&) = default;
    TinyPbStruct(TinyPbStruct&&)                 = default;
    TinyPbStruct& operator=(TinyPbStruct&&)      = default;

    int32_t     pk_len{0};       // len of all package(include start char and end char)
    int32_t     msg_req_len{0};  // len of msg_req
    std::string msg_req;         // msg_req, which identify a request

    int32_t     service_name_len{0};  // len of service full name
    std::string service_full_name;    // service full name, like QueryService.query_name

    int32_t     err_code{0};
    int32_t     err_info_len{0};  // len of err_info
    std::string err_info;  // err_info, empty -- call rpc success, otherwise -- call rpc failed, it will display details
                           // of reason why call rpc failed. it only be seted by RpcController
    std::string pb_data;   // business pb data
    int32_t     check_num{-1};  // check_num of all package. to check legality of data
};

}  // namespace tinyrpc
