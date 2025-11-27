default: fmt demo
check: clean fmt doc test

info=cmake -E cmake_echo_color "--switch=$(COLOR)" --cyan

build:
	@$(info) "Configuring build-system..."
	@mkdir -p bin
	@cmake -B bin
	@$(info) "Compiling everything..."
	@make -sC bin all

clean:
	@$(info) "Removing artefacts..."
	@git clean -fXd

fmt:
	@$(info) "Formatting..."
	@find src/ -iname '*.[ch]' | xargs clang-format -i --verbose

test: build
	@make -sC bin test

demo: build
	@$(info) "Running the demo..."
	@./bin/src/demo/demo

doc:
	@$(info) "Generating documentation..."
	@doxygen

install: build
	@$(info) "Installing the library..."
	@sudo cmake --install bin

remove:
	@$(info) "Uninstalling the library..."
	@sudo rm -fv /usr/local/lib/libmostly-trees.*
	@sudo rm -rfv /usr/local/include/mostly-trees
