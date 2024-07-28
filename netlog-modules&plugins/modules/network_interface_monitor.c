#include "network_interface_monitor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ifaddrs.h>
#include <linux/if_link.h>

void monitor_network_interfaces() {
    struct ifaddrs *ifaddr, *ifa;
    int family, n;
    
    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    printf("Network interfaces:\n");
    for (ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++) {
        if (ifa->ifa_addr == NULL)
            continue;

        family = ifa->ifa_addr->sa_family;

        printf("%-8s %s (%d)\n",
               ifa->ifa_name,
               (family == AF_PACKET) ? "AF_PACKET" :
               (family == AF_INET) ? "AF_INET" :
               (family == AF_INET6) ? "AF_INET6" : "???",
               family);

        if (family == AF_PACKET && ifa->ifa_data != NULL) {
            struct rtnl_link_stats *stats = ifa->ifa_data;
            printf("  RX packets: %10u; TX packets: %10u\n"
                   "  RX bytes:   %10u; TX bytes:   %10u\n",
                   stats->rx_packets, stats->tx_packets,
                   stats->rx_bytes, stats->tx_bytes);
        }
    }

    freeifaddrs(ifaddr);
}
