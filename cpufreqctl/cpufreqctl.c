// Copyright (C) 2017 Fioratto Raffaele

// This program is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.

// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
// more details.

// You should have received a copy of the GNU General Public License along
// with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <stdio.h>
#include <string.h>

void print_usage() {
    fprintf(stderr, "usage: cpufreqctl [-h] [turbo {get,0,1}] [min {get,check,VALUE}] [max {get,VALUE}]\n");
}

void help_turbo() {
    fprintf(stderr, "turbo parameters:\n");
    fprintf(stderr, "    get          get the current turbo boost state\n");
    fprintf(stderr, "    0            turn turbo boost off\n");
    fprintf(stderr, "    1            turn turbo boost on\n\n");
}

void help_max() {
    fprintf(stderr, "max parameters:\n");
    fprintf(stderr, "    get          get the current set maximum frequency (in %%, [0;100])\n");
    fprintf(stderr, "    VALUE        set the current maximum frequency to a value in [0;100]\n\n");
}

void help_min() {
    fprintf(stderr, "min parameters:\n");
    fprintf(stderr, "    get          get the current set minimum frequency (in %%, [0;100])\n");
    fprintf(stderr, "    VALUE        set the current minimum frequency to a value in [0;100]\n\n");
}

int main(int argc, char** argv) {
    FILE* f;
    if (argc < 2) {
        print_usage();
        fprintf(stderr, "error: you must specify an action!\n");
        return -1;
    }

    if (!(strcmp(argv[1], "turbo"))) {
        if (argc < 3) {
            fprintf(stderr, "usage: cpufreqctl turbo {get,0,1}\n");
            help_turbo();
            return -2;
        }

        if (!(strcmp(argv[2], "get"))) {
            f = fopen("/sys/devices/system/cpu/intel_pstate/no_turbo", "r");
            if (f == NULL) {
                perror("Cannot open file \'/sys/devices/system/cpu/intel_pstate/no_turbo\'");
                return -3;
            }
            printf("%c\n", fgetc(f));
            fclose(f);
            return 0;
        } else if (!(strcmp(argv[2], "0"))) {
            f = fopen("/sys/devices/system/cpu/intel_pstate/no_turbo", "w");
            if (f == NULL) {
                perror("Cannot open \'/sys/devices/system/cpu/intel_pstate/no_turbo\'");
                return -3;
            }
            fputc('0', f);
            fclose(f);
            return 0;
        } else if (!(strcmp(argv[2], "1"))) {
            f = fopen("/sys/devices/system/cpu/intel_pstate/no_turbo", "w");
            if (f == NULL) {
                perror("Cannot open /sys/devices/system/cpu/intel_pstate/no_turbo\'");
                return -3;
            }
            fputc('1', f);
            fclose(f);
            return 0;
        } else {
            fprintf(stderr, "usage: cpufreqctl turbo {get,0,1}\n");
            fprintf(stderr, "error: VALUE must be 0 or 1\n");
            return -2;
        }
    } else if (!(strcmp(argv[1], "max"))) {
        int perc;
        if (argc < 3) {
            fprintf(stderr, "usage: cpufreqctl max {get,VALUE}\n");
            help_max();
            return -2;
        }

        if (!(strcmp(argv[2], "get"))) {
            char value[5];
            memset(value, 0, 5);

            f = fopen("/sys/devices/system/cpu/intel_pstate/max_perf_pct", "r");
            if (f == NULL) {
                perror("Cannot open \'/sys/devices/system/cpu/intel_pstate/max_perf_pct\'");
                return -3;
            }

            if (fgets(value, 4, f) != value) {
                perror("Cannot read from \'/sys/devices/system/cpu/intel_pstate/max_perf_pct\'");
                return -4;
            }

            printf("%s\n", value);

            fclose(f);

            return 0;
        } else if (sscanf(argv[2], "%d", &perc) > 0 && perc >= 0 && perc <= 100) {
            f = fopen("/sys/devices/system/cpu/intel_pstate/max_perf_pct", "w");

            if (f == NULL) {
                perror("Cannot open \'/sys/devices/system/cpu/intel_pstate/max_perf_pct\'");
                return -3;
            }

            fprintf(f, "%d", perc);

            fclose(f);

            return 0;
        } else {
            fprintf(stderr, "usage: cpufreqctl max {get,VALUE}\n");
            fprintf(stderr, "error: VALUE must be between 0 and 100\n");
            return -2;
        }
    } else if (!(strcmp(argv[1], "min"))) {
        int perc;
        if (argc < 3) {
            fprintf(stderr, "usage: cpufreqctl min {get,VALUE}\n");
            help_min();
            return -2;
        }

        if (!(strcmp(argv[2], "get"))) {
            char value[5];
            memset(value, 0, 5);

            f = fopen("/sys/devices/system/cpu/intel_pstate/min_perf_pct", "r");

            if (f == NULL) {
                perror("Cannot open \'/sys/devices/system/cpu/intel_pstate/min_perf_pct\'");
                return -3;
            }

            if (fgets(value, 4, f) != value) {
                perror("Cannot read from \'/sys/devices/system/cpu/intel_pstate/min_perf_pct\'");
                return -4;
            }

            printf("%s\n", value);

            fclose(f);

            return 0;
        } else if (sscanf(argv[2], "%d", &perc) > 0 && perc >= 0 && perc <= 100) {
            f = fopen("/sys/devices/system/cpu/intel_pstate/min_perf_pct", "w");

            if (f == NULL) {
                perror("Cannot open file \'/sys/devices/system/cpu/intel_pstate/min_perf_pct\'");
                return -3;
            }

            fprintf(f, "%d", perc);

            fclose(f);

            return 0;
        } else {
            fprintf(stderr, "usage: cpufreqctl min {get,VALUE}\n");
            fprintf(stderr, "error: VALUE must be between 0 and 100\n");
            return -2;
        }
    }
}