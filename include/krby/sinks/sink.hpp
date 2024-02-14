#pragma once

#include <cstdint>
#include <vector>

namespace krby
{
    namespace sink
    {
        class Sink
        {
          public:
            virtual void write(std::vector<uint8_t> bytes) = 0;
            virtual ~Sink() = default;
        };

    } // namespace sink

} // namespace krby
