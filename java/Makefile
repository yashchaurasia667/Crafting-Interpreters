JAVA = java
JAVAC = javac

BUILD_DIR = build
SRC_DIR = com/craftinginterpreters/lox

default: run

jlox: $(SRC_DIR)/Lox.java
	mkdir -p $(BUILD_DIR)
	$(JAVAC) -d (BUILD_DIR) $(SRC_DIR)/Lox.java

run: $(SRC_DIR)/Lox.java
	$(JAVA) $(SRC_DIR)/Lox.java

clean: 
	rm -rf $(BUILD_DIR)