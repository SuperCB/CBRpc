#pragma once
#include "coroutine/coroutine.h"
#include "coroutine/memory.h"
#include "net/mutex.h"
#include <vector>

namespace tinyrpc {

class CoroutinePool {

public:
    CoroutinePool(int pool_size, int stack_size = 1024 * 128);
    ~CoroutinePool();

    Coroutine::ptr getCoroutineInstanse();

    void returnCoroutine(Coroutine::ptr cor);

private:
    int m_pool_size{0};
    int m_stack_size{0};

    // first--ptr of cor
    // second
    //    false -- can be dispatched
    //    true -- can't be dispatched
    std::vector<std::pair<Coroutine::ptr, bool>> m_free_cors;

    Mutex m_mutex;

    std::vector<Memory::ptr> m_memory_pool;
};

CoroutinePool* GetCoroutinePool();

}  // namespace tinyrpc
