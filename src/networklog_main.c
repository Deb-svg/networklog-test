#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <ifaddrs.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

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
    } else if (strcmp(argv[1], "help") == 0) {
        show_help();
    } else {
        fprintf(stderr, "Unknown command: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

// Function declarations
void show_help();
void start_logging();
void stop_logging();
void show_status();
void display_log();
void check_network();
void list_interfaces();
void show_stats();
void monitor_network();
void generate_report();
void archive_logs();

// Global variables
int logging = 0;
FILE *log_file = NULL;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: No command provided.\n");
        show_help();
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "help") == 0) {
        show_help();
    } else if (strcmp(argv[1], "start") == 0) {
        start_logging();
    } else if (strcmp(argv[1], "stop") == 0) {
        stop_logging();
    } else if (strcmp(argv[1], "status") == 0) {
        show_status();
    } else if (strcmp(argv[1], "log") == 0) {
        display_log();
    } else if (strcmp(argv[1], "check") == 0) {
        check_network();
    } else if (strcmp(argv[1], "list-interfaces") == 0) {
        list_interfaces();
    } else if (strcmp(argv[1], "stats") == 0) {
        show_stats();
    } else if (strcmp(argv[1], "monitor") == 0) {
        monitor_network();
    } else if (strcmp(argv[1], "report") == 0) {
        generate_report();
    } else if (strcmp(argv[1], "archive") == 0) {
        archive_logs();
    } else {
        fprintf(stderr, "Error: Invalid command '%s'.\n", argv[1]);
        show_help();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void show_help() {
    printf("NetworkLog - Network Logging Tool\n");
    printf("Usage: networklog <command>\n");
    printf("Commands:\n");
    printf("  help               Show this help message\n");
    printf("  start              Start network logging\n");
    printf("  stop               Stop network logging\n");
    printf("  status             Show logging status\n");
    printf("  log                Display current log\n");
    printf("  check              Check network status\n");
    printf("  list-interfaces    List network interfaces\n");
    printf("  stats              Show network statistics\n");
    printf("  monitor            Monitor network activity\n");
    printf("  report             Generate network report\n");
    printf("  archive            Archive logs\n");
}

void start_logging() {
    if (logging) {
        printf("Network logging is already started.\n");
        return;
    }

    log_file = fopen("networklog.txt", "a");
    if (log_file == NULL) {
        perror("Error opening log file");
        return;
    }

    time_t now = time(NULL);
    fprintf(log_file, "Logging started at %s\n", ctime(&now));
    logging = 1;
    printf("Network logging started.\n");
}

void stop_logging() {
    if (!logging) {
        printf("Network logging is not running.\n");
        return;
    }

    time_t now = time(NULL);
    fprintf(log_file, "Logging stopped at %s\n", ctime(&now));
    fclose(log_file);
    log_file = NULL;
    logging = 0;
    printf("Network logging stopped.\n");
}

void show_status() {
    if (logging) {
        printf("Network logging is running.\n");
    } else {
        printf("Network logging is stopped.\n");
    }
}

void display_log() {
    FILE *file = fopen("networklog.txt", "r");
    if (file == NULL) {
        perror("Error opening log file");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

void check_network() {
    printf("Checking network status...\n");
    system("ping -c 4 google.com");
}

void list_interfaces() {
    struct ifaddrs *interfaces, *ifa;
    if (getifaddrs(&interfaces) == -1) {
        perror("getifaddrs");
        return;
    }

    printf("Network interfaces:\n");
    for (ifa = interfaces; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL) continue;
        if (ifa->ifa_addr->sa_family == AF_INET) {
            char addr[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &((struct sockaddr_in *)ifa->ifa_addr)->sin_addr, addr, INET_ADDRSTRLEN);
            printf("%s\t%s\n", ifa->ifa_name, addr);
        }
    }

    freeifaddrs(interfaces);
}

void show_stats() {
    printf("Network statistics:\n");
    system("netstat -i");
}

void monitor_network() {
    printf("Monitoring network activity...\n");
    system("tcpdump -c 10 -i any");
}

void generate_report() {
    printf("Generating network report...\n");
    // Sample report generation
    system("ifconfig > network_report.txt");
    printf("Report generated: network_report.txt\n");
}

void archive_logs() {
    printf("Archiving logs...\n");
    system("tar -czf networklog_archive.tar.gz networklog.txt");
    printf("Logs archived: networklog_archive.tar.gz\n");
}
