#include "logger.h"
#include "../error/error.h"
#include <stdlib.h>

struct hcb_logger {
	hcb_error_t *err;
};

hcb_logger_t *new_hcb_logger() {
	struct hcb_logger *log;
	log = malloc(sizeof(&log));
	log->err = new_hcb_error();
	return log;
}
