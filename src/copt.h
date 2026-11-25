#ifndef OPTION_H
#define OPTION_H

#include <stdbool.h>

struct copt {
	bool empty;
	void* data;
};

typedef struct copt copt;
typedef struct copt Option;

Option option_some(void* data);
Option option_none(void);
bool option_is_some(Option option);
bool option_is_none(Option option);
void* option_unwrap_or(Option option, void* default_value);

#endif
