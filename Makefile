# Makefile

# Executable
EXECS=SHA512

# Command to run
SHA512: SHA512.c
	cc -o SHA512 SHA512.c

test: tests.sh
	./tests.sh

# Force clean files
clean:
	rm -f $(EXECS)
	
