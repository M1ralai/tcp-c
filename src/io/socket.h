
#ifndef HCB_SOCKET
#define HCB_SOCKET

#include "../error/error.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct hcb_socket hcb_socket_t;

hcb_socket_t *hcb_new_socket(hcb_error_t *err);

void hcb_socket_start(hcb_socket_t *sock, const char *port);

void *hcb_socket_free(hcb_socket_t *sock);

#ifdef __cplusplus
}
#endif

#endif
