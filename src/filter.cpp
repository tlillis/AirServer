#include "../include/filter.h"
#include <iostream>

Filter::Filter() {
	set_all(1);
}

int Filter::set_all(int message_div) {
	for(int i = 0; i < NUM_MESSAGES; i++) {
		this->set(i, message_div);
	}
	return 1;
}

int Filter::set(int message_num, int message_div) {
	if(message_num >= NUM_MESSAGES || message_num < 0) return -1;
	counter[message_num] = 1;
	rate[message_num] = message_div;
	//std::cout << message_num << "-" <<rate[message_num] << ":" << counter[message_num] << std::endl;

	//std::cout << "SET: " << rate[message_num] << std::endl;
	return 0;
}

int Filter::check(int message_num) {
	//std::cout << message_num << "-" <<rate[message_num] << ":" << counter[message_num] << std::endl;
	if(message_num >= NUM_MESSAGES || message_num < 0) return 0;
	if(rate[message_num] <= 0) return 0;
	if(rate[message_num] <= counter[message_num]) {
		counter[message_num] = 1;
		return 1;
	}
	counter[message_num]++;

	return 0;
}

int Filter::get_rate(int message_num) {
	return rate[message_num];
}

int Filter::print_rate_all() {
	for(int i = 0; i < NUM_MESSAGES; i++) {
		if(get_rate(i)) {
			std::cout << i << ":" << get_rate(i) << std::endl;
		}
	}
	std::cout << std::endl;
	return 1;
}
