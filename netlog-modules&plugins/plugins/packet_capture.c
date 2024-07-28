#include "packet_capture.h"
#include <stdio.h>
#include <pcap.h>

void capture_packets(const char *dev) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return;
    }

    printf("Capturing packets on device %s...\n", dev);

    pcap_loop(handle, 10, packet_handler, NULL);

    pcap_close(handle);
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Captured a packet with length of [%d]\n", header->len);
}
