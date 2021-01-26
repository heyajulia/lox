bin/lox: $(wildcard src/*.c src/*.h)
	mkdir -p bin
	clang -o bin/lox -DDEBUG_TRACE_EXECUTION -W -Wall -Werror -Wextra -Wpedantic $(wildcard src/*.c)

clean:
	rm -rf bin

.PHONY: clean
