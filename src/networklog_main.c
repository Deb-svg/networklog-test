#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "network_interface_monitor.h"
#include "packet_capture.h"

#define LOG_FILE "/var/log/networklog.log"
#define REPORT_FILE "/var/log/network_report.log"

void log_message(const char *message) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }

    time_t now = time(NULL);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0'; // Remove the newline character
    fprintf(log_file, "[%s] %s\n", time_str, message);
    fclose(log_file);
}

void generate_report(const char *report) {
    FILE *report_file = fopen(REPORT_FILE, "a");
    if (report_file == NULL) {
        perror("Unable to open report file");
        exit(EXIT_FAILURE);
    }

    time_t now = time(NULL);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0'; // Remove the newline character
    fprintf(report_file, "[%s] %s\n", time_str, report);
    fclose(report_file);
}

void show_help() {
    printf("NetworkLog - Network Logging Tool\n");
    printf("Usage:\n");
    printf("  networklog start     - Start logging network activity\n");
    printf("  networklog stop      - Stop logging network activity\n");
    printf("  networklog log       - Log a custom message\n");
    printf("  networklog report    - Generate a network report\n");
    printf("  networklog monitor   - Monitor network interfaces\n");
    printf("  networklog capture   - Capture network packets\n");
    printf("  networklog help      - Show this help message\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        show_help();
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "start") == 0) {
        log_message("Network logging started");
        printf("Network logging started\n");
    } else if (strcmp(argv[1], "stop") == 0) {
        log_message("Network logging stopped");
        printf("Network logging stopped\n");
    } else if (strcmp(argv[1], "log") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Please provide a message to log\n");
            return EXIT_FAILURE;
        }
        log_message(argv[2]);
        printf("Logged message: %s\n", argv[2]);
    } else if (strcmp(argv[1], "report") == 0) {
        generate_report("Network report generated");
        printf("Network report generated\n");
    } else if (strcmp(argv[1], "monitor") == 0) {
        monitor_network_interfaces();
    } else if (strcmp(argv[1], "capture") == 0) {
        if (argc < 3) {
            fprintf(stderr, "Please provide a network interface to capture on\n");
            return EXIT_FAILURE;
        }
        capture_packets(argv[2]);
    } else if (strcmp(argv[1], "help") == 0) {
        show_help();
    } else {
        fprintf(stderr, "Unknown command: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
