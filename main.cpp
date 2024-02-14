#include "krby/decoders/raw.hpp"
#include "krby/encoders/timestamped_hex.hpp"
#include "krby/krby.hpp"
#include "krby/sinks/stdout.hpp"
#include "krby/sources/tcp_client.hpp"

using namespace krby;

int main()
{
    source::TCPClient client{"0.0.0.0", 8080};
    sink::StdoutSink stdoutSink{true};

    decoder::Raw rawDecoder{};
    encoder::TimeStampedHexEncoder encoder{};

    Link link{client, stdoutSink, rawDecoder, encoder};

    link.run();
}
