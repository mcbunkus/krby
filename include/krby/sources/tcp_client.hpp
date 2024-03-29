#pragma once

#include "krby/sources/source.hpp"

#include <cstdint>
#include <string>
#include <vector>

namespace krby
{
    namespace source

    {
        // create a TCP client class that implements Source and Sink
        class TCPClient : public Source
        {
            int m_fd;

          public:
            TCPClient(const std::string &hostname, uint16_t port);
            std::size_t read(std::vector<uint8_t> &bytes) override;
        };

    } // namespace source

} // namespace krby
