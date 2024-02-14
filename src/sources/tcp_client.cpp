#include "krby/sources/tcp_client.hpp"

#include <arpa/inet.h>
#include <stdexcept>
#include <sys/socket.h>

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

        std::size_t TCPClient::read(std::vector<uint8_t> &bytes)
        {
            // read from the TCP server
            ssize_t n = recv(m_fd, bytes.data(), bytes.size(), 0);
            if (n == -1)
            {
                throw std::runtime_error("Failed to read from the socket");
            }

            if (n == 0)
            {
                throw std::runtime_error("Connection closed");
            }

            return n;
        }
    } // namespace source

} // namespace krby
