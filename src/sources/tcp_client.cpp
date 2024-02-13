#include "krby/sources/tcp_client.hpp"

#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdexcept>

namespace krby
{
    namespace source
    {
        TCPClient::TCPClient(const std::string &hostname, uint16_t port)
        {
            // create a socket and connect to the server
            m_fd = socket(AF_INET, SOCK_STREAM, 0);
            if (m_fd == -1)
            {
                throw std::runtime_error("Failed to create a socket");
            }

            struct sockaddr_in server;
            server.sin_family = AF_INET;
            server.sin_port = htons(port);
            if (inet_pton(AF_INET, hostname.c_str(), &server.sin_addr) <= 0)
            {
                throw std::runtime_error("Invalid address");
            }

            if (connect(m_fd, (struct sockaddr *)&server, sizeof(server)) < 0)
            {
                throw std::runtime_error("Connection failed");
            }
        }

        std::vector<uint8_t> TCPClient::read()
        {
            // read from the TCP server
            std::vector<uint8_t> buffer(4096);
            ssize_t n = recv(m_fd, buffer.data(), buffer.size(), 0);
            if (n == -1)
            {
                throw std::runtime_error("Failed to read from the socket");
            }

            if (n == 0)
            {
                throw std::runtime_error("Connection closed");
            }

            buffer.resize(n);
            return buffer;
        }
    } // namespace source

} // namespace krby
