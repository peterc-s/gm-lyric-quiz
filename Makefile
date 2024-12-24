CC = gcc
CFLAGS ?= -O2 -lm -lraylib
CFLAGS += $(CFLAGS_EX)

SRCDIR = src
BUILDDIR = build

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)

INSTALL_DIR = /usr/bin

all : gm-quiz

gm-quiz : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILDDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

run : gm-quiz
	./gm-quiz $(ARGS)

clean:
	-rm -r $(BUILDDIR)
	-rm gm-quiz

install : gm-quiz
	-mkdir $$HOME/.cache/gm-quiz
	cp $(wildcard resources/*.ttf) $$HOME/.cache/gm-quiz
	sudo cp gm-quiz $(INSTALL_DIR)/gm-quiz

uninstall :
	rm -r $$HOME/.cache/gm-quiz
	sudo rm $(INSTALL_DIR)/gm-quiz

.PHONY: all clean run install uninstall
