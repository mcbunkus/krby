#include "krby/decoders/raw.hpp"
#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <vector>

namespace krby
{
    namespace decoder
    {

        std::vector<uint8_t> Raw::decode(source::Source &source)
        {
            std::vector<uint8_t> buffer(4096);
            std::size_t nread = source.read(buffer);

            if (nread == -1)
            {
                throw std::runtime_error(
                    std::string{"failed to read from source: "} +
                    std::strerror(errno));
            }

            buffer.resize(nread);

            return buffer;
        }
    } // namespace decoder
} // namespace krby
