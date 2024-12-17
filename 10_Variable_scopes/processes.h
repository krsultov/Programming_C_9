#ifndef PROCESSES_H
#define PROCESSES_H

struct Process {
  int id;
  char name[30];
};

extern struct Process processes[5];
extern int process_count;

static int next_process_id();

#endif
