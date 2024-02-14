#pragma once

#include "krby/encoders/encoder.hpp"

namespace krby
{
    namespace encoder
    {
        class TimeStampedHexEncoder : public Encoder
        {
          public:
            void encode(sink::Sink &sink,
                        const std::vector<uint8_t> &bytes) override;

            ~TimeStampedHexEncoder() = default;
        };

    } // namespace encoder
} // namespace krby
