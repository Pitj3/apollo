#ifndef apollo_macros_h__
#define apollo_macros_h__

#include <cstddef>
#include <cstdint>

#if defined(APOLLO_PLATFORM_WINDOWS)
#define DEBUG_BREAK __debugbreak()
#elif defined(APOLLO_PLATFORM_LINUX)
#include <signal.h>
#define DEBUG_BREAK raise(SIGTRAP)
#include <signal.h>
#elif defined(APOLLO_PLATFORM_MAC)
#define DEBUG_BREAK raise(SIGTRAP)
#endif

#ifdef APOLLO_ENABLE_ASSERTS
#define APOLLO_ASSERT(x, ...) { if(!(x)) { PRIMAL_ERROR("Assertion Failed: {0}", __VA_ARGS__); DEBUG_BREAK; } }
#define APOLLO_INTERNAL_ASSERT(x, ...) { if(!(x)) { PRIMAL_INTERNAL_ERROR("Assertion Failed: {0}", __VA_ARGS__); DEBUG_BREAK; } }
#else
#define APOLLO_ASSERT(x, ...)
#define APOLLO_INTERNAL_ASSERT(x, ...)
#endif

#if defined (APOLLO_DEBUG)
#define DEBUG_ONLY_BLOCK(block) block
#define RELEASE_ONLY_BLOCK(block)
#define DEBUG_RELEASE_TOGGLE_BLOCK(dbg, rel) dbg
#else
#define DEBUG_ONLY_BLOCK(block)
#define RELEASE_ONLY_BLOCK(block) block
#define DEBUG_RELEASE_TOGGLE_BLOCK(dbg, rel) rel
#endif 

#define APOLLO_NO_COPY(cls)                                                    \
    cls(const cls&) = delete;                                                  \
    cls& operator=(const cls&) = delete;

#define APOLLO_NO_MOVE(cls)                                                    \
    cls(cls&&) noexcept = delete;                                              \
    cls& operator=(cls&&) noexcept = delete;

#define APOLLO_NO_COPY_MOVE(cls)                                               \
    APOLLO_NO_COPY(cls)                                                        \
    APOLLO_NO_MOVE(cls)

#define APOLLO_NO_DISCARD [[nodiscard]]

using s8 = int8_t;
using u8 = uint8_t;
using s16 = int16_t;
using u16 = uint16_t;
using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;
using f32 = float;
using f64 = double;

#endif // apollo_macros_h__