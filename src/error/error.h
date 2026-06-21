#ifndef HCB_SERVER_ERROR
#define HCB_SERVER_ERROR

#ifdef __cplusplus
extern "C" {
#endif

typedef struct hcb_error hcb_error_t;

hcb_error_t *new_hcb_error();

hcb_error_t *hcb_error_get(hcb_error_t *err);

void hcb_error_set(hcb_error_t *err, char *msg, int status);

#ifdef __cplusplus
}
#endif

#endif
