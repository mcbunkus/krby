#pragma once

#include <cstdint>
#include <vector>

#include "krby/sinks/sink.hpp"

namespace krby
{
    namespace encoder
    {
        class Encoder
        {
          public:
            virtual void encode(sink::Sink &sink,
                                const std::vector<uint8_t> &bytes) = 0;

            virtual ~Encoder() = default;
        };

    } // namespace encoder
} // namespace krby
