#include "types.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]) {
	int oldfd, newfd;
	oldfd = open("testold", O_RDWR|O_CREATE);
	//can be any number between 0-15
	newfd = dup2(oldfd, 15);
	if (write(oldfd, "dup ", 3) < 0 ) {
		printf(2, "failed");
		exit();
	}
	if (write(newfd, "worked!\n", 8) < 0) {
		printf(2, "failed");
		exit();
	}
	printf(2, "success");
	exit();
}
