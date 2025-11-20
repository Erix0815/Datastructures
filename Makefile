default: fmt demo
check: clean fmt doc test

build:
	@mkdir -p bin
	@cmake -B bin
	@make -sC bin all

clean:
	@git clean -fXd

fmt:
	@find src/ -iname '*.h' -o -iname '*.c' | xargs clang-format -i

test: build
	@make -sC bin test

demo: build
	@./bin/src/demo/demo

doc:
	@doxygen Doxyfile

install: build
	@sudo cmake --install bin

remove:
	@sudo rm -fv /usr/local/lib/libmostly-trees.*
	@sudo rm -rfv /usr/local/include/mostly-trees
