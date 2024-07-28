CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = networklog
SRC = src/networklog_main.c
BIN_DIR = bin

.PHONY: all clean install test

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$(TARGET) $(SRC)

clean:
	rm -f $(BIN_DIR)/$(TARGET) networklog.txt network_report.txt networklog_archive.tar.gz

install: $(TARGET)
	install -d /usr/local/bin
	install $(BIN_DIR)/$(TARGET) /usr/local/bin
	install $(BIN_DIR)/networklog /usr/local/bin

test: $(TARGET)
	chmod +x scripts/test_networklog.sh
	./scripts/test_networklog.sh

# Additional rules to install the bash script and other files
install-scripts:
	install -d /usr/local/bin
	install $(BIN_DIR)/networklog.bash /usr/local/bin/networklog.bash
	install scripts/install.sh /usr/local/bin/install_networklog.sh

install-all: install install-scripts
