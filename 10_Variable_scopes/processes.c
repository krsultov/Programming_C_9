#include "processes.h"
#include <limits.h>

static int next_process_id() {
    static int id = 0;

    if (process_count == UINT_MAX) {
        return 0;
    }

    return id++;
}
