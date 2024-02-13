#include "krby/link.hpp"

#include <iostream>
#include <stdexcept>

namespace krby
{

    Link::Link(source::Source &source, sink::Sink &sink) : m_source(source), m_sink(sink)
    {
    }

    void Link::record(encoder::Encoder &encoder)
    {

        while (true)
        {

            // read from the source, encode, and write to the sink
            try
            {
                std::vector<uint8_t> bytes = m_source.read();
                std::vector<uint8_t> encoded = encoder.encode(bytes);
                m_sink.write(encoded);
            }
            catch (const std::runtime_error &e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
                break;
            }
        }
    }

    void Link::replay(decoder::Decoder &decoder)
    {

        while (true)
        {
            // read from the source, decode, and write to the sink
            try
            {
                std::vector<uint8_t> bytes = m_source.read();
                std::vector<uint8_t> decoded = decoder.decode(bytes);
                m_sink.write(decoded);
            }
            catch (const std::runtime_error &e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
                break;
            }
        }
    }

} // namespace krby
