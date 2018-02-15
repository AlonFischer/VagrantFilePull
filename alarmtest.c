#include "types.h"
#include "stat.h"
#include "user.h"

void periodic();

int
main(int argc, char *argv[])
{
  int i;
  printf(1, "alarmtest starting\n");
  alarm(2, periodic);
  for(i = 0; i < 25*500000; i++){
    if((i % 250000) == 0)
      write(2, ".", 1);
  }
  exit();
}

void
periodic()
{
  printf(1, "alarm!\n");
  asm("movl 16(%ebp), %eax");
  asm("movl 12(%ebp), %edx");
  asm("movl 8(%ebp), %ecx");
  register int eax asm("%eax");
  register int ecx asm("%ecx");
  register int edx asm("%edx");
  printf(1, "After: eax: %d, ecx: %d, edx: %d", eax, ecx, edx);
}
