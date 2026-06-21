#ifndef HCB_SERVER_H
#define HCB_SERVER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { HCB_PROTOCOL_TCP, HCP_PROTOCOL_UDP, HCP_PROTOCOL_HTTP, HCP_PROTOCOL_MAX } hcb_protocol_t;

typedef struct hcb_server hcb_server_t;

hcb_server_t *new_hcb_server(const char *port, hcb_protocol_t protocol);

int hcb_server_start(hcb_server_t *server);

void hcb_server_destroy(hcb_server_t *server);

#ifdef __cplusplus
}
#endif
#endif
