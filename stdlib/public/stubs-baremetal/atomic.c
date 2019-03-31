#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#define DEFINE_VARIANTS         \
    PROTOTYPE(1, uint8_t)       \
    PROTOTYPE(2, uint16_t)      \
    PROTOTYPE(4, uint32_t)      \
    PROTOTYPE(8, uint64_t)


//
// ATOMIC LOAD
//

#define PROTOTYPE(n,t)                                                      \
t __atomic_load_##n(t* ptr, int memorder) {                                 \
    return *ptr;                                                            \
}
DEFINE_VARIANTS
#undef PROTOTYPE

void __atomic_load (size_t size, void *mem, void *ret, int model) {
    memcpy(ret, mem, size);
}

//
// ATOMIC STORE
//

#define PROTOTYPE(n,t)                                                      \
void __atomic_store_##n(t* ptr, t val, int memorder) {                      \
    *ptr = val;                                                             \
}
DEFINE_VARIANTS
#undef PROTOTYPE

void __atomic_store(size_t size, void* ptr, void* val, int memorder) {
    memcpy(ptr, val, size);
}

//
// ATOMIC EXCHANGE
//

#define PROTOTYPE(n,t)                                                      \
t __atomic_exchange_##n(t* ptr, t val, int memorder) {                      \
    t temp = *ptr;                                                          \
    *ptr = val;                                                             \
    return temp;                                                            \
}
DEFINE_VARIANTS
#undef PROTOTYPE

void __atomic_exchange(size_t size, uint8_t* ptr, uint8_t* val,
                       uint8_t* ret, int mo)
{
    for (int i = 0; i < size; i++) {
        ret[i] = ptr[i];
        ptr[i] = val[i];
    }
}

//
// ATOMIC COMPARE & EXCHANGE
//

#define PROTOTYPE(n,t)                                                      \
bool __atomic_compare_exchange_##n(t *ptr, t *expected,                     \
                                   t desired, bool weak,                    \
                                   int success_memorder,                    \
                                   int failure_memorder)                    \
{                                                                           \
    if (*ptr == *expected) {                                                \
        *ptr = desired;                                                     \
        return true;                                                        \
    } else {                                                                \
        *expected = *ptr;                                                   \
        return false;                                                       \
    }                                                                       \
}
DEFINE_VARIANTS
#undef PROTOTYPE

bool __atomic_compare_exchange(size_t size, uint8_t* ptr, uint8_t* expected,
                               uint8_t* desired, bool weak, int sm, int fm)
{
    if (memcmp(ptr, expected, size) == 0) {
        memcpy(ptr, desired, size);
        return true;
    } else {
        memcpy(expected, ptr, size);
        return false;
    }
}

#undef DEFINE_VARIANTS

//
// ATOMIC OP + FETCH
//

#define DEFINE_VARIANTS              \
    PROTOTYPE(add, +, 1, uint8_t)       \
    PROTOTYPE(add, +, 2, uint16_t)      \
    PROTOTYPE(add, +, 4, uint32_t)      \
    PROTOTYPE(add, +, 8, uint64_t)      \
    PROTOTYPE(sub, -, 1, uint8_t)       \
    PROTOTYPE(sub, -, 2, uint16_t)      \
    PROTOTYPE(sub, -, 4, uint32_t)      \
    PROTOTYPE(sub, -, 8, uint64_t)      \


uint32_t __atomic_fetch_add_4(uint32_t* ptr, uint32_t val, int mo) {
    uint32_t tmp = *ptr;
    *ptr += val;
    return tmp;
}

uint32_t __atomic_fetch_sub_4(uint32_t* ptr, uint32_t val, int mo) {
    uint32_t tmp = *ptr;
    *ptr -= val;
    return tmp;
}


//
// SYNC
//

uint32_t __sync_fetch_and_add_4(uint32_t* ptr, uint32_t val, ...) {
    uint32_t temp = *ptr;
    *ptr += val;
    return temp;
}

uint64_t __sync_fetch_and_add_8(uint64_t* ptr, uint64_t val, ...) {
    uint64_t temp = *ptr;
    *ptr += val;
    return temp;
}

uint32_t __sync_fetch_and_and_4(uint32_t* ptr, uint32_t val, ...) {
    uint32_t temp = *ptr;
    *ptr &= val;
    return temp;
}

uint64_t __sync_fetch_and_and_8(uint64_t* ptr, uint64_t val, ...) {
    uint64_t temp = *ptr;
    *ptr &= val;
    return temp;
}

uint32_t __sync_fetch_and_or_4(uint32_t* ptr, uint32_t val, ...) {
    uint32_t temp = *ptr;
    *ptr |= val;
    return temp;
}

uint64_t __sync_fetch_and_or_8(uint64_t* ptr, uint64_t val, ...) {
    uint64_t temp = *ptr;
    *ptr |= val;
    return temp;
}

uint32_t __sync_fetch_and_xor_4(uint32_t* ptr, uint32_t val, ...) {
    uint32_t temp = *ptr;
    *ptr ^= val;
    return temp;
}

uint64_t __sync_fetch_and_xor_8(uint64_t* ptr, uint64_t val, ...) {
    uint64_t temp = *ptr;
    *ptr ^= val;
    return temp;
}

uint32_t __sync_lock_test_and_set_4(uint32_t* ptr, uint32_t val, ...) {
    uint32_t temp = *ptr;
    *ptr = val;
    return *ptr;
}

uint64_t __sync_lock_test_and_set_8(uint64_t* ptr, uint64_t val, ...) {
    uint64_t temp = *ptr;
    *ptr = val;
    return *ptr;
}

void __sync_synchronize() {
}

uint8_t __sync_val_compare_and_swap_1(uint8_t* ptr, uint8_t oldval, uint8_t newval, ...) {
    uint8_t backup = *ptr;
    if (*ptr == oldval) {
        *ptr = newval;
    }
    return backup;
}

uint32_t __sync_val_compare_and_swap_4(uint32_t* ptr, uint32_t oldval, uint32_t newval, ...) {
    uint32_t backup = *ptr;
    if (*ptr == oldval) {
        *ptr = newval;
    }
    return backup;
}

uint64_t __sync_val_compare_and_swap_8(uint64_t* ptr, uint64_t oldval, uint64_t newval, ...) {
    uint64_t backup = *ptr;
    if (*ptr == oldval) {
        *ptr = newval;
    }
    return backup;
}
