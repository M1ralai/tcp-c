#include "server.h"

#include <stdio.h>
#include <stdlib.h>

#include "../error/error.h"
#include "../io/socket.h"

struct hcb_server {
	hcb_socket_t *sock;
	hcb_error_t *err;
};

hcb_server_t *hcb_new_server(hcb_socket_t *sock) {
	hcb_server_t *ret = malloc(sizeof(*ret));
	hcb_error_t *err = hcb_new_error("Server");
	ret->err = err;
	ret->sock = sock;
	return ret;
}

void hcb_server_start(hcb_server_t *server, int debug_err) {
	puts("Server Started");
	if (debug_err == 1) {
		hcb_error_set(server->err, "debug server error");
	}
}

hcb_server_t *hcb_server_free(hcb_server_t *server) {
	if (server->err != NULL) {
		hcb_error_free(server->err);
	}
	if (server->sock != NULL) {
		hcb_socket_free(server->sock);
	}
	return NULL;
}

hcb_error_t *hcb_server_get_error(hcb_server_t *server) {
	return server->err;
}
