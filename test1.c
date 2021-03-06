#include "userthread.h"
#include "ll.h"

void testfunc1(){
  printf("start\n");
  for (int i = 0; i < 10; i++){
    printf("one testing %d\n", i);
  }
  printf("done test one\n");
}

void testfunc2(){
  for (int i = 0; i < 10; i++){
    printf("two testing %d\n", i);
  }
  printf("done test two\n");
}

void testfunc3(){
  for (int i = 0; i < 10; i++){
    printf("three testing %d\n", i);
    if (i == 5){
      thread_yield();
    }
  }
  printf("done test three\n");
}

void testfunc4(){
  for (int i = 0; i < 10; i++){
    printf("four testing %d\n", i);
  }
  printf("done test four\n");
}

void testfunc5(){
  for (int i = 0; i < 10; i++){
    printf("five testing %d\n", i);
  }
  printf("done test five\n");
}

int main(){
  printf("Testing...\n");
  thread_libinit(FIFO);
  int one = thread_create(testfunc1, NULL, 1);
  int two = thread_create(testfunc2, NULL, -1);
  int three = thread_create(testfunc3, NULL, 0);
  int four = thread_create(testfunc4, NULL, 0);
  int five = thread_create(testfunc5, NULL, -1);
  thread_join(two);
  thread_join(one);
  thread_join(five);
  thread_join(three);
  thread_join(four);
  
  thread_libterminate();
  printf("exiting\n");
  return 0;
}
