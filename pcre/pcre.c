#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <pcre.h>

#define OVECCOUNT 30

int
main(int argc, char **argv)
{
	pcre *re;
	int rc;
	int erroffset;
	int ovector[OVECCOUNT];
	char *pattern;
	const char *error;
	char line[1000];

	if (argc < 2)
		errx(1, "usage: prog regexp");

	pattern = argv[1];
	re = pcre_compile(
	    pattern, /* the pattern */
	    0, /* default options */
	    &error, /* for error message */
	    &erroffset, /* for error offset */
	    NULL); /* use default character tables */

	if (re == NULL) {
		errx(1, "pcre_compile failed");
	}

	while (1) {
		printf("> ");
		if (fgets(line, sizeof(line), stdin) == NULL) {
			break;
		}

		rc = pcre_exec(
		    re, /* copmiled pattern */
		    NULL, /* no extra data - we didn't study the pattern */
		    line, /* the subject string */
		    strlen(line), /* the length of the subject */
		    0, /* start at offset 0 in the subject */
		    0, /* default options */
		    ovector, /* output vector for substring information */
		    OVECCOUNT); /* number of elements in the output vector */
		if (rc >= 0) {
			fputs(line, stdout);
		}
	}
}
