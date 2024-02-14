#pragma once

#include "krby/decoders/decoder.hpp"
#include "krby/encoders/encoder.hpp"
#include "krby/sinks/sink.hpp"
#include "krby/sources/source.hpp"

namespace krby
{
    // Link combines a Source and a Sink with an Encoder or a Decoder
    // to record or replay data from the source to the sink
    class Link
    {
        source::Source &m_source;
        sink::Sink &m_sink;

        decoder::Decoder &m_decoder;
        encoder::Encoder &m_encoder;

      public:
        Link(source::Source &source, sink::Sink &sink,
             decoder::Decoder &decoder, encoder::Encoder &encoder);

        void run();
    };

} // namespace krby
