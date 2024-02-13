#include "krby/encoders/hex.hpp"
#include <cstdio>

namespace krby
{

    namespace encoder
    {

        std::vector<uint8_t> HexEncoder::encode(std::vector<uint8_t> bytes)
        {
            std::vector<uint8_t> encoded;
            for (uint8_t byte : bytes)
            {
                char hex[3];
                snprintf(hex, sizeof(hex), "%02x", byte);
                encoded.push_back(hex[0]);
                encoded.push_back(hex[1]);
            }
            return encoded;
        }

    } // namespace encoder

} // namespace krby
