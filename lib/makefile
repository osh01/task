all: find-lib
# to make static library
	ar rvs find-lib.a find-lib
find-lib: source.cc
	g++ -c source.cc -o find-lib -lstdc++fs

clear:
	rm find-lib