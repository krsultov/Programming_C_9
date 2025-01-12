#ifndef PROCESSES_H
#define PROCESSES_H

struct Process {
  unsigned int id;
  char name[30];
};

extern struct Process processes[5];
extern int process_count;

unsigned int next_process_id();

unsigned int create_new_process(char name[30]);

#endif
