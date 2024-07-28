#ifndef PACKET_CAPTURE_H
#define PACKET_CAPTURE_H

void capture_packets(const char *dev);
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

#endif // PACKET_CAPTURE_H
