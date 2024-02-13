#pragma once

#include <vector>
#include <cstdint>

namespace krby
{
    namespace encoder
    {
        class Encoder
        {
        public:
            virtual std::vector<uint8_t> encode(std::vector<uint8_t> bytes) = 0;
            virtual ~Encoder() = default;
        };

    } // namespace encoder
} // namespace krby
