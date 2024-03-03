#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>
#include <netdb.h>

#define SERVER_ADDR "ntp2.aliyun.com" // NTP server address
#define SERVER_PORT 123              // NTP server port

// Define NTP Timestamp Format
struct ntp_packet {
    unsigned char li_vn_mode;      // Leap indicator, Version, Mode
    unsigned char stratum;         // Stratum level
    unsigned char poll;            // Poll interval
    unsigned char precision;       // Precision
    uint32_t root_delay;           // Root delay
    uint32_t root_dispersion;      // Root dispersion
    uint32_t ref_id;               // Reference ID
    uint32_t ref_ts_secs;          // Reference timestamp (seconds)
    uint32_t ref_ts_frac;          // Reference timestamp (fractions)
    uint32_t orig_ts_secs;         // Origin timestamp (seconds)
    uint32_t orig_ts_frac;         // Origin timestamp (fractions)
    uint32_t rx_ts_secs;           // Received timestamp (seconds)
    uint32_t rx_ts_frac;           // Received timestamp (fractions)
    uint32_t tx_ts_secs;           // Transmit timestamp (seconds)
    uint32_t tx_ts_frac;           // Transmit timestamp (fractions)
};

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd;
    struct sockaddr_in server_address;
    struct ntp_packet packet;
    memset(&packet, 0, sizeof(struct ntp_packet));

    // Set first byte to 0x1B which corresponds to NTP client request
    *((char *) &packet) = 0x1B;

    // Create a UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockfd < 0) 
        error("ERROR opening socket");

    // Set server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);

    // if (inet_pton(AF_INET, SERVER_ADDR, &server_address.sin_addr) <= 0)
    //     error("ERROR invalid server address");
struct hostent *server;
    server = gethostbyname(SERVER_ADDR);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);

    // Send request to the server
    if (sendto(sockfd, (char*) &packet, sizeof(struct ntp_packet), 0, (struct sockaddr*)&server_address, sizeof(server_address)) < 0)
        error("ERROR in sendto");

    // Receive response from the server
    socklen_t server_address_len = sizeof(server_address);
    if (recvfrom(sockfd, (char*) &packet, sizeof(struct ntp_packet), 0, (struct sockaddr*)&server_address, &server_address_len) < 0)
        error("ERROR in recvfrom");

    // Timestamp starts at byte 32
    packet.tx_ts_secs = ntohl(packet.tx_ts_secs); // Time-stamp seconds.
    packet.tx_ts_frac = ntohl(packet.tx_ts_frac); // Time-stamp fraction of a second.
    
    // The time is 70 years plus 17 leap years ahead of Unix time (seconds)
    const time_t NTP_TIMESTAMP_DELTA = 2208988800ull;
    time_t txTimestamp = (time_t)(packet.tx_ts_secs - NTP_TIMESTAMP_DELTA);

    // Convert and print the received time
    printf("Time received from server: %s", ctime((const time_t *)&txTimestamp));

    // Close the socket
    close(sockfd);

    return 0;
}
