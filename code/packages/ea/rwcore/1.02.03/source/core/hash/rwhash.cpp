#include "rwsharedheaders.hpp"
#include <limits.h>
#include <stdlib.h>
#include "rw/core/hash/hash.h"



namespace
{
const uint32_t rw_32_PRIME = 0x01000193u;
const uint64_t rw_64_PRIME = 0x100000001b3;
}

namespace rw
{

const uint32_t RWHASH32_INIT = 0x811c9dc5u;
const uint64_t RWHASH64_INIT = 0xcbf29ce484222325;

uint32_t RwHash32UInt32(uint32_t integer, uint32_t hashValue)
{
    hashValue *= rw_32_PRIME;
    hashValue ^= (uint32_t)(integer & 0xff);
    integer >>= 8;
    hashValue *= rw_32_PRIME;
    hashValue ^= (uint32_t)(integer & 0xff);
    integer >>= 8;
    hashValue *= rw_32_PRIME;
    hashValue ^= (uint32_t)(integer & 0xff);
    integer >>= 8;
    hashValue *= rw_32_PRIME;
    hashValue ^= (uint32_t)(integer & 0xff);

    return hashValue
}

uint32_t RwHash32Buffer(const uint8_t *buffer, size_t length, uint32_t hashValue)
{
    const uint8_t *bufferEnd = buffer + length;

    rwASSERT(buffer != NULL);
    rwASSERT(length > 0);

    while (buffer < bufferEnd)
    {
        hashValue *= rw_32_PRIME;
        hashValue ^= (uint32_t)(*buffer++);
    }

    return hashValue;
}

uint32_t RwHash32String(const RwChar *str, uint32_t hashValue)
{
    const uint8_t *s = (const uint8_t *)str;

    rwASSERT(str != NULL);

    while (*s)
    {
        hashValue *= rw_32_PRIME;
        hashValue ^= (uint32_t)(*s++);
    }

    return hashValue;
}

uint64_t RwHash64Buffer(const uint8_t *buffer, size_t length, uint64_t hashValue)
{
    const uint8_t *bufferEnd = buffer + length;

    rwASSERT(buffer != NULL);
    rwASSERT(length > 0);

    while (buffer < bufferEnd)
    {
        hashValue *= rw_64_PRIME;
        hashValue ^= (uint64_t)(*buffer++);
    }

    return hashValue;
}

uint64_t RwHash64String(const RwChar *str, uint64_t hashValue)
{
    const uint8_t *s = (const uint8_t *)str;

    rwASSERT(str != NULL);

    while (*s)
    {
        hashValue *= rw_64_PRIME;
        hashValue ^= (uint64_t)(*s++);
    }

    return hashValue;
}

}