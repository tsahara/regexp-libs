#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "oniguruma.h"

int
main(int argc, char **argv)
{
	regex_t *reg;
	const char *pat;
	OnigErrorInfo err_info;
	OnigPosition pos;
	int ret;
	char line[1000];

	if (argc < 2)
		errx(1, "usage: prog regexp");

	pat = argv[1];
	ret = onig_new(&reg, pat, pat+strlen(pat), ONIG_OPTION_NONE,
			ONIG_ENCODING_ASCII, ONIG_SYNTAX_RUBY,
			&err_info);
	if (ret != ONIG_NORMAL) {
		char buf[ONIG_MAX_ERROR_MESSAGE_LEN];
		onig_error_code_to_str(buf, ret);
		errx(1, "onig_new failed: %s", buf);
	}

	while (fgets(line, sizeof(line), stdin) != NULL) {
		if (onig_search(reg, line, line + strlen(line), line,
		                line + strlen(line), NULL, 0) >= 0)
			fputs(line, stdout);
	}
}
