CC = gcc
CFLAGS = -Wall
PREFIX = /usr/local
TARGET = thinkpoint
AUTOSTART_PATH = /etc/xdg/autostart

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)

.PHONY: install

install: $(TARGET)
	mkdir -p $(PREFIX)/bin
	cp $< $(PREFIX)/bin/$(TARGET)
	cp $<.desktop $(AUTOSTART_PATH)
	chmod +s $(PREFIX)/bin/$(TARGET)

.PHONY: uninstall
uninstall:
	rm -f $(PREFIX)/bin/$(TARGET) $(AUTOSTART_PATH)/$(TARGET).desktop

