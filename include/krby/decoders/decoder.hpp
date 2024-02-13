#pragma once

#include <vector>
#include <cstdint>

namespace krby
{
    namespace decoder
    {

        class Decoder
        {
        public:
            virtual std::vector<uint8_t> decode(std::vector<uint8_t> bytes) = 0;
            virtual ~Decoder() = default;
        };

    } // namespace krby

} // namespace name