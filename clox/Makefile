SRC_DIR = src
DIST_DIR = dist
TARGET = $(DIST_DIR)/clox
SRC = $(wildcard $(SRC_DIR)/*.c)

$(TARGET): $(SRC) | $(DIST_DIR)
	clang -Wall -Wextra -o $(TARGET) $(SRC)

$(DIST_DIR):
	mkdir -p $(DIST_DIR)

run: $(TARGET)
	./$(TARGET)

