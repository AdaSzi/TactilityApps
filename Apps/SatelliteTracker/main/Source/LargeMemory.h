#pragma once

#include <cstddef>

/** Allocates big buffers in external RAM (PSRAM) when the device has it. */
void* largeAlloc(size_t size);
void largeFree(void* pointer);

/** std::vector allocator that keeps the elements in external RAM when available. */
template <typename T>
struct LargeAllocator {
    using value_type = T;

    LargeAllocator() = default;

    template <typename U>
    LargeAllocator(const LargeAllocator<U>&) {}

    T* allocate(size_t count) { return static_cast<T*>(largeAlloc(count * sizeof(T))); }
    void deallocate(T* pointer, size_t) { largeFree(pointer); }

    template <typename U>
    bool operator==(const LargeAllocator<U>&) const { return true; }
    template <typename U>
    bool operator!=(const LargeAllocator<U>&) const { return false; }
};
