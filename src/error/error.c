#include "error.h"
#include <stdlib.h>
#include <string.h>

struct hcb_error {
	char msg[256];
	int status;
};

hcb_error_t *hcb_error_get(hcb_error_t *err) {
	return err;
}

void hcb_error_set(hcb_error_t *err, char *msg, int status) {
	strcpy(err->msg, msg);
	err->status = status;
}

hcb_error_t *new_hcb_error() {
	struct hcb_error *hcb_err;
	hcb_err = malloc(sizeof(&hcb_err));
	return hcb_err;
}
