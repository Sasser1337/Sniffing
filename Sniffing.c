#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/ip_icmp.h>
#include <net/ethernet.h>

int main()
{
    int sock_raw;
    int saddr_size;
    struct sockaddr_in saddr;
    struct in_addr in;
    struct iphdr *iph;
    struct tcphdr *tcph;
    struct udphdr *udph;
    struct icmphdr *icmph;
    char *buffer = (char *)malloc(65536);
    int data_size;

    sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock_raw < 0) {
        printf("Socket Error\n");
        return 1;
    }

    while (1) {
        saddr_size = sizeof(saddr);
        data_size = recvfrom(sock_raw, buffer, 65536, 0, (struct sockaddr *)&saddr, &saddr_size);
        if (data_size < 0) {
            printf("Recvfrom error , failed to get packets\n");
            return 1;
        }

        iph = (struct iphdr *)buffer;
        switch (iph->protocol) {
            case 1:
                icmph = (struct icmphdr *)(buffer + (iph->ihl * 4));
                printf("\n\n***********************ICMP Packet*************************\n");
                in.s_addr = iph->saddr;
                printf("IP Header\n");
                printf("   |-Source IP        : %s\n", inet_ntoa(in));
                in.s_addr = iph->daddr;
                printf("   |-Destination IP   : %s\n", inet_ntoa(in));
                printf("ICMP Header\n");
                printf("   |-Type : %d\n", (unsigned int)(icmph->type));
                break;

            case 6:
                tcph = (struct tcphdr *)(buffer + (iph->ihl * 4));
                printf("\n\n***********************TCP Packet*************************\n");
                in.s_addr = iph->saddr;
                printf("IP Header\n");
                printf("   |-Source IP        : %s\n", inet_ntoa(in));
                in.s_addr = iph->daddr;
                printf("   |-Destination IP   : %s\n", inet_ntoa(in));
                printf("TCP Header\n");
                printf("   |-Source Port      : %u\n", ntohs(tcph->source));
                printf("   |-Destination Port : %u\n", ntohs(tcph->dest));
                break;

            case 17:
                udph = (struct udphdr *)(buffer + (iph->ihl * 4));
                printf("\n\n***********************UDP Packet*************************\n");
                in.s_addr = iph->saddr;
                printf("IP Header\n");
                printf("   |-Source IP        : %s\n", inet_ntoa(in));
                in.s_addr = iph->daddr;
                printf("   |-Destination IP   : %s\n", inet_ntoa(in));
                printf("UDP Header\n");
                printf("   |-Source Port      : %u\n", ntohs(udph->source));
                printf("   |-Destination Port : %u\n", ntohs(udph->dest));
                break;

            default:
                printf("Unknown Protocol\n");
                break;
        }
    }
    close(sock_raw);
    printf("Finished");
    return 0;
}