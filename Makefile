CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = networklog
SRC = networklog_main.c netlog-modules&plugins/modules/network_interface_monitor.c netlog-modules&plugins/plugins/packet_capture.c
BIN_DIR = ..

.PHONY: all clean install install-scripts test

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/bin/$(TARGET) $(SRC)

clean:
	rm -f $(BIN_DIR)/bin/$(TARGET) $(BIN_DIR)/networklog.log $(BIN_DIR)/network_report.log $(BIN_DIR)/networklog_archive.tar.gz

install: $(TARGET)
	install -d /usr/local/bin
	install $(BIN_DIR)/bin/$(TARGET) /usr/local/bin
	install $(BIN_DIR)/bin/networklog /usr/local/bin

test: $(TARGET)
	chmod +x test_networklog.sh
	./test_networklog.sh

install-scripts:
	install -d /usr/local/bin
	install $(BIN_DIR)/bin/networklog.bash /usr/local/bin/networklog.bash
	install install.sh /usr/local/bin/install_networklog.sh

install-all: install install-scripts
