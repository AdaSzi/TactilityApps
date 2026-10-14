#include "LargeMemory.h"

#include <tactility/memory.h>

void* largeAlloc(size_t size) {
    constexpr MemoryPolicy policy = { .required = 0, .desired = MEMORY_CAPABILITY_EXTERNAL, .alignment = 0 };
    return memory_alloc_with_policy(size, &policy);
}

void largeFree(void* pointer) {
    memory_free(pointer);
}
