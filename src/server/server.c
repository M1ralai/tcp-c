#include "server.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Protokollerin davranışlarını soyutlayan fonksiyon göstericisi (function pointer) tanımı
typedef int (*listener_func_t)(const char *port);

// 2. Her protokole ait private listener fonksiyonları
static int listen_tcp(const char *port) {
	printf("TCP is not implemented yet");
	return 0;
}

static int listen_udp(const char *port) {
	printf("UDP is not implemented yet");
	return 0;
}

static int listen_http(const char *port) {
	printf("HTPP is not implemented yet");
	return 0;
}

static const listener_func_t PROTOCOL_REGISTRY[HCP_PROTOCOL_MAX] = {
	[HCB_PROTOCOL_TCP] = listen_tcp, [HCP_PROTOCOL_UDP] = listen_udp, [HCP_PROTOCOL_HTTP] = listen_http};

struct hcb_server {
	char *port;
	hcb_protocol_t protocol;
	int listener_fd;
};

hcb_server_t *new_hcb_server(const char *port, hcb_protocol_t protocol) {
	hcb_server_t *srv = malloc(sizeof(hcb_server_t));
	if (!srv)
		return NULL;

	srv->port = strdup(port);
	srv->protocol = protocol;
	srv->listener_fd = -1;
	return srv;
}
