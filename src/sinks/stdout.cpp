#include "krby/sinks/stdout.hpp"
#include <iostream>

namespace krby
{
    namespace sink
    {

        StdoutSink::StdoutSink(bool newline) : m_newline(newline) {}

        void StdoutSink::write(std::vector<uint8_t> bytes)
        {
            // write the bytes to stdout
            for (uint8_t byte : bytes)
            {
                std::cout << byte;
            }

            if (m_newline)
            {
                std::cout << '\n';
            }
        }

    } // namespace sink

} // namespace krby
