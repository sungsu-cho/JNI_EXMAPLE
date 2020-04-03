DYLD_LIBRARY_PATH="$(pwd)/bin:$(DYLD_LIBRARY_PATH)"

all:
	@mkdir -p ./bin/
	cd src;make $@

clean:
	@rm -rf ./bin/
	cd src;make $@

run:
	@java -classpath bin -Djava.library.path=bin JNIHashtable