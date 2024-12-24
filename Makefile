CMAKE_FLAGS = -DCMAKE_BUILD_TYPE=Release

SRCDIR = src
BUILDDIR = build
INSTALLDIR = /usr/bin

TARGET = gm-quiz

all: ${BUILDDIR}/Makefile
	$(MAKE) -C $(BUILDDIR)

${BUILDDIR}/Makefile:
	@echo "Creating build directory..."
	@mkdir -p $(BUILDDIR)
	@echo "Copying resources to build directory..."
	@mkdir -p $(BUILDDIR)/resources
	@cp -r resources/* $(BUILDDIR)/resources
	@echo "Running CMake..."
	@cmake $(CMAKE_FLAGS) -B$(BUILDDIR) -H.
	@echo "DONE!"

clean:
	@echo "Removing build directory..."
	@rm -rf $(BUILDDIR)
	@echo "DONE!"

run: all
	@$(BUILDDIR)/$(TARGET)

install: all
	@echo "Creating cache directory at $(HOME)/.cache/gm-quiz..."
	@-mkdir $$HOME/.cache/gm-quiz
	@echo "Copying resources to cache directory..."
	@cp $(wildcard resources/*.ttf) $$HOME/.cache/gm-quiz
	@echo "Installing to $(INSTALLDIR)..."
	@sudo cp $(BUILDDIR)/$(TARGET) $(INSTALLDIR)
	@echo "DONE!"

uninstall:
	@echo "Removing cache directory at $(HOME)/.cache/gm-quiz..."
	@rm -r $$HOME/.cache/gm-quiz
	@echo "Uninstalling from $(INSTALLDIR)..."
	@sudo rm $(INSTALLDIR)/$(TARGET)
	@echo "DONE!"

.PHONY: all clean run install uninstall
