#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <regex.h>

int
main(int argc, char **argv)
{
	regex_t reg;
	const char *pat;
	int ret;
	char line[1000];

	if (argc < 2)
		errx(1, "usage: prog regexp");

	pat = argv[1];
	ret = regcomp(&reg, pat, REG_EXTENDED);
	if (ret != 0) {
		errx(1, "regcomp failed");
	}

	while (fgets(line, sizeof(line), stdin) != NULL) {
		if (regexec(&reg, line, 0, NULL, 0) == 0)
			fputs(line, stdout);
	}
}
