#include "krby/encoders/timestamped_hex.hpp"
#include <chrono>
#include <cstdio>

namespace krby
{

    namespace encoder
    {

        void TimeStampedHexEncoder::encode(sink::Sink &sink,
                                           const std::vector<uint8_t> &bytes)
        {
            std::vector<uint8_t> encoded;

            // get the current date and time and convert it to a human readable
            // string
            auto now = std::chrono::system_clock::now();
            auto now_t = std::chrono::system_clock::to_time_t(now);
            char timestamp[20];
            strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S",
                     std::localtime(&now_t));

            // convert the string to bytes and append them to encoded
            for (char c : timestamp)
            {
                encoded.push_back(c);
            }

            encoded.push_back('\t');

            for (uint8_t byte : bytes)
            {
                char hex[3];
                snprintf(hex, sizeof(hex), "%02x", byte);
                encoded.push_back(hex[0]);
                encoded.push_back(hex[1]);
            }

            sink.write(encoded);
        }

    } // namespace encoder

} // namespace krby
