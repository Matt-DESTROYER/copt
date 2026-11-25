#include "copt.h"

#include <stdbool.h>
#include <stddef.h>

Option option_some(void* data) {
	return (Option){
		.empty = false,
		.data = data
	};
}

Option option_none() {
	return (Option){
		.empty = true,
		.data = NULL
	};
}

bool option_is_some(Option option) {
	return !option.empty;
}

bool option_is_none(Option option) {
	return option.empty;
}

void* option_unwrap(Option option) {
	if (option.empty)
		return NULL;
	return option.data;
}

void* option_unwrap_or(Option option, void* default_value) {
	if (option.empty)
		return default_value;
	return option.data;
}
