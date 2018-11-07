/* SPDX-License-Identifier: MIT */
/*
 * Copyright (C) 2018 Wireguard LLC
 */

#include "server.h"o

#include <stdlib.h>
#include <stdio.h>

const char *PROG_NAME;

static void show_usage()
{
	fprintf(stderr, "Usage: %s <interface>\n\n", PROG_NAME);
}

int main(int argc, char *argv[])
{
	PROG_NAME = argv[0];

	if (argc == 1) {
		show_usage();
		return EXIT_FAILURE;
	}

    if (setup_server(argv[1]) < 0) {
        perror("error setting up server");
        return EXIT_FAILURE;
    }

	return EXIT_SUCCESS;
}