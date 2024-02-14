#pragma once

#include "krby/decoders/decoder.hpp"
namespace krby
{
    namespace decoder
    {
        class Raw : public Decoder
        {
          public:
            std::vector<uint8_t> decode(source::Source &source) override;
        };
    } // namespace decoder
} // namespace krby
