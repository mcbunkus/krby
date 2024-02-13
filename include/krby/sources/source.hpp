#pragma once

#include <vector>
#include <cstdint>

namespace krby
{
    namespace source
    {

        class Source
        {
        public:
            virtual std::vector<uint8_t> read() = 0;
            virtual ~Source() = default;
        };

    } // namespace krby

} // namespace source