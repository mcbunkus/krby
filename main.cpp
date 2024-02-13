#include "krby/krby.hpp"
#include "krby/sources/tcp_client.hpp"
#include "krby/sinks/stdout.hpp"
#include "krby/encoders/hex.hpp"
#include "krby/encoders/timestamped_hex.hpp"

using namespace krby;

int main()
{
    source::TCPClient client{"0.0.0.0", 8080};
    sink::StdoutSink stdoutSink{true};

    Link link{client, stdoutSink};

    encoder::TimeStampedHexEncoder encoder{};

    link.record(encoder);
}