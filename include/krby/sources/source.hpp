#pragma once

#include <cstdint>
#include <vector>

namespace krby
{
    namespace source
    {

        class Source
        {
          public:
            virtual std::size_t read(std::vector<uint8_t> &bytes) = 0;
            virtual ~Source() = default;
        };

    } // namespace source

} // namespace krby
