#ifndef HCB_SERVER_ERROR
#define HCB_SERVER_ERROR

#ifdef __cplusplus
extern "C" {
#endif

typedef struct hcb_error hcb_error_t;

hcb_error_t *hcb_error_get();

void hcb_error_set(char *msg, int status);

#ifdef __cplusplus
}
#endif

#endif
