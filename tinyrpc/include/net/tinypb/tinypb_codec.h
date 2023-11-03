#pragma once
#include "net/abstract_codec.h"
#include "net/abstract_data.h"
#include "net/tinypb/tinypb_data.h"
#include <stdint.h>

namespace tinyrpc {

class TinyPbCodeC: public AbstractCodeC {
public:
    // typedef std::shared_ptr<TinyPbCodeC> ptr;

    TinyPbCodeC();

    ~TinyPbCodeC();

    // overwrite
    void encode(TcpBuffer* buf, AbstractData* data);

    // overwrite
    void decode(TcpBuffer* buf, AbstractData* data);

    // overwrite
    virtual ProtocalType getProtocalType();

    const char* encodePbData(TinyPbStruct* data, int& len);
};

}  // namespace tinyrpc
