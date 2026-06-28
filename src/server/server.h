#ifndef HCB_SERVER_H
#define HCB_SERVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../error/error.h"
#include "../io/socket.h"

typedef struct hcb_server hcb_server_t;

hcb_server_t *hcb_new_server(hcb_socket_t *port);

void hcb_server_start(hcb_server_t *server, int debug_err);

hcb_server_t *hcb_server_free(hcb_server_t *server);

hcb_error_t *hcb_server_get_error(hcb_server_t *server);

#ifdef __cplusplus
}
#endif
#endif
