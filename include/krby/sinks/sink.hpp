#pragma once

#include <vector>
#include <cstdint>

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

    } // namespace krby

} // namespace sink