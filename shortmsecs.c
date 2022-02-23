#include <uwsgi.h>

extern struct uwsgi_server uwsgi;

static ssize_t uwsgi_lf_shortmsecs(struct wsgi_request *wsgi_req, char **buf) {
    *buf = uwsgi_malloc(4);
    snprintf(*buf, 4, "%03lu", (wsgi_req->start_of_request / (int64_t) 1000) % 1000);
    return strlen(*buf);
}

static void register_logchunks() {
    uwsgi_register_logchunk("shortmsecs", uwsgi_lf_shortmsecs, 1);
}

struct uwsgi_plugin shortmsecs_plugin = {
        .name = "shortmsecs",
        .on_load = register_logchunks,
};

