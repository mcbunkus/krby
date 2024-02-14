#include "krby/link.hpp"

#include <iostream>
#include <stdexcept>
#include <vector>

namespace krby
{

    Link::Link(source::Source &source, sink::Sink &sink,
               decoder::Decoder &decoder, encoder::Encoder &encoder)
        : m_source(source), m_sink(sink), m_decoder(decoder), m_encoder(encoder)
    {
    }

    void Link::run()
    {
        while (true)
        {

            // read from the source, encode, and write to the sink
            try
            {
                std::vector<uint8_t> bytes = m_decoder.decode(m_source);
                m_encoder.encode(m_sink, bytes);
            }
            catch (const std::runtime_error &e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
                break;
            }
        }
    }

} // namespace krby
