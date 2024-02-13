#pragma once

#include "krby/sources/source.hpp"
#include "krby/sinks/sink.hpp"
#include "krby/encoders/encoder.hpp"
#include "krby/decoders/decoder.hpp"

namespace krby
{
    // Link combines a Source and a Sink with an Encoder or a Decoder
    // to record or replay data from the source to the sink
    class Link
    {
        source::Source &m_source;
        sink::Sink &m_sink;

    public:
        Link(source::Source &source, sink::Sink &sink);
        void record(encoder::Encoder &encoder);
        void replay(decoder::Decoder &decoder);
    };

} // namespace krby
