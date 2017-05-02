bin_PROGRAMS = cpufreqctl

cpufreqctl_CFLAGS = -Wall -Wextra -Wconversion -Wsign-conversion -Wformat-security -Werror -fstack-protector-all -Wstack-protector -pie -fPIE -D_FORTIFY_SOURCE=2 -O2 -Wl,-z,relro,-z,now

cpufreqctl_SOURCES = cpufreqctl.c

install-exec-hook:
	@echo    "#### Setting SUID for cpufreqctl. ####"
	chmod 4755 $(DESTDIR)$(bindir)/cpufreqctl
	@echo    "####------------------------------####"
