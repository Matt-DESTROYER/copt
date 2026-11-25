#include "copt.h"

#include <stdbool.h>
#include <stddef.h>

Option option_new() {
	return (Option){
		.empty = true,
		.data = NULL
	};
}

void option_some(Option option, void* data) {
	option.empty = false;
	option.data = data;
}

void option_none(Option option) {
	option.data = NULL;
	option.empty = true;
}

bool option_is_some(Option option) {
	return !option.empty;
}

bool option_is_none(Option option) {
	return option.empty;
}

void* option_unwrap_or(Option option, void* default_value) {
	if (!option.empty)
		return option.data;
	return default_value;
}
