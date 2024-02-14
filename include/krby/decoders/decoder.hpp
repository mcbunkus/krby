#pragma once

#include <cstdint>
#include <vector>

#include "krby/sources/source.hpp"

namespace krby
{
    namespace decoder
    {

        /**
         * @brief Decoder is an interface that describes how to read a Source
         * to produce a writable set of bytes
         */
        class Decoder
        {
          public:
            virtual std::vector<uint8_t> decode(source::Source &source) = 0;

            virtual ~Decoder() = default;
        };

    } // namespace decoder

} // namespace krby
