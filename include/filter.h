#ifndef FILTER_H
#define FILTER_H

#define NUM_MESSAGES 255

class Filter {

public:
    Filter();

    int set_all(int message_div);
    int set(int message_num, int message_div);
    int check(int message_num);
    int get_rate(int message_num);
    int print_rate_all();

private:
    int rate[NUM_MESSAGES];
    int counter[NUM_MESSAGES];
};

#endif // FILTER_H