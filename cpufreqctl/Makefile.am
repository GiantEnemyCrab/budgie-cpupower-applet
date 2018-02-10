bin_PROGRAMS = cpufreqctl

cpufreqctl_CFLAGS = -Wall -Wextra -Wconversion -Wsign-conversion -Wformat-security -Werror -fstack-protector-all -Wstack-protector -pie -fPIE -D_FORTIFY_SOURCE=2 -O2 -Wl,-z,relro,-z,now

cpufreqctl_SOURCES = cpufreqctl.c

policydir = $(datarootdir)/polkit-1/actions
policy_DATA = polkit/actions/rf.cpupower.policy

rulesdir = $(datarootdir)/polkit-1/rules.d
rules_DATA = polkit/rules.d/rf.cpupower.rules

install-exec-hook:
	chmod 555 $(DESTDIR)$(bindir)/cpufreqctl
