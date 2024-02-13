#pragma once

#include "krby/encoders/encoder.hpp"

namespace krby
{
    namespace encoder
    {
        class HexEncoder : public Encoder
        {
        public:
            std::vector<uint8_t> encode(std::vector<uint8_t> bytes) override;
            ~HexEncoder() = default;
        };

    } // namespace encoder
} // namespace krby
