JAVA = java
JAVAC = javac

BUILD_DIR = build
SRC_DIR = com/craftinginterpreters/lox

default: jlox

jlox: $(SRC_DIR)/Lox.java
	mkdir -p $(BUILD_DIR)
	$(JAVA) $(SRC_DIR)/Lox.java

clean: 
	rm -rf $(BUILD_DIR)