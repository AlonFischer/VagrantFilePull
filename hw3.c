#include "types.h"
#include "user.h"
#include "fcntl.h"


void test(int n);

int main (int argc, char *argv[]) {
	//comment out other tests while trying to run each test

	//printf(1, "testing part 3.1\n");
	//printf(1, "trying negative argument\n");
	//sbrk(-1);

	//printf(1, "testing 3.2\n");
	//test(0);
	
	printf(1, "testing 3.3\n");
        int *n = (int *)sbrk(10);
	pipe(n);
	
	exit();
}

void test(int n) {
	printf(1, "%d\n", &n);
	test(n+1);
}
