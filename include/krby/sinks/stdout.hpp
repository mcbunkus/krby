#pragma once

#include "krby/sinks/sink.hpp"

namespace krby

{
    namespace sink

    {
        class StdoutSink : public Sink
        {
            bool m_newline = false;

        public:
            StdoutSink() = default;
            StdoutSink(bool newline);

            void write(std::vector<uint8_t> bytes) override;
            ~StdoutSink() = default;
        };

    } // namespace sink

} // namespace krby
