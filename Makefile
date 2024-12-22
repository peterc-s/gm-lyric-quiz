CC = gcc
CFLAGS ?= -O2 -D_FORTIFY_SOURCE=3 -Wformat -Werror=format-security -fstack-clash-protection -fstack-protector-all -fcf-protection -s -Wl,-z,relro,-z,now -lm -lraylib
CFLAGS += $(CFLAGS_EX)

SRCDIR = src
BUILDDIR = build

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)

INSTALL_DIR = /usr/bin

NAME = gm-quiz

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILDDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

run : $(NAME)
	./$(NAME) $(ARGS)

clean:
	-rm -r $(BUILDDIR)
	-rm $(NAME)

install : $(NAME)
	-mkdir $$HOME/.cache/$(NAME)
	cp $(wildcard resources/*.ttf) $$HOME/.cache/$(NAME)
	sudo cp $(NAME) $(INSTALL_DIR)/$(NAME)

uninstall :
	rm -r $$HOME/.cache/$(NAME)
	sudo rm $(INSTALL_DIR)/$(NAME)

.PHONY: all clean run install uninstall
