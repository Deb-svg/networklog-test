#!/bin/bash

COMMAND=$1
shift

log_message() {
    echo "$(date +"%Y-%m-%d %H:%M:%S") - $1" >> /var/log/networklog.log
}

case "$COMMAND" in
    start)
        networklog start
        log_message "Network logging started via script"
        ;;
    stop)
        networklog stop
        log_message "Network logging stopped via script"
        ;;
    log)
        MESSAGE=$1
        networklog log "$MESSAGE"
        log_message "Custom log message: $MESSAGE"
        ;;
    report)
        networklog report
        log_message "Network report generated via script"
        ;;
    help)
        networklog help
        ;;
    *)
        echo "Unknown command: $COMMAND"
        echo "Usage: networklog {start|stop|log|report|help}"
        exit 1
        ;;
esac
