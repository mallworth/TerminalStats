#include <stdio.h>
#include <sys/utsname.h>
#include <stdlib.h>
#include <sys/sysctl.h>
#include <time.h>
#include <openGL/gl.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/ioctl.h>
#include <sys/statvfs.h>
#include <math.h>


char *execute_system_command(const char *command) {
    FILE *pipe = popen(command, "r");

    if (pipe == NULL) {
        return NULL;
    }

    char *output = NULL;
    char buffer[128];
    size_t output_size = 0;

    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        size_t buffer_len = strlen(buffer);
        output = realloc(output, output_size + buffer_len + 1);

        if (output == NULL) {
            fclose(pipe);
            return NULL; 
        }

        strcpy(output + output_size, buffer);
        output_size += buffer_len;
    }

    pclose(pipe);
    return output;
}


int main() {
	// Sys info
    struct utsname unameData;
    uname(&unameData);

    // CPU info
    char cpu[50];
    size_t cpu_len = sizeof(cpu);
    sysctlbyname("machdep.cpu.brand_string", &cpu, &cpu_len, NULL, 0);

    // OS info
    int mib[2];
    size_t len;
    char *kernel_version;
    mib[0] = CTL_KERN;
    mib[1] = KERN_OSRELEASE;

    sysctl(mib, 2, NULL, &len, NULL, 0);
    kernel_version = (char *)malloc(len * sizeof(char));
    sysctl(mib, 2, kernel_version, &len, NULL, 0);

    // Shell info
    FILE *f;
    char version[50];
    f = popen("bash --version | head -n 1", "r");
    fgets(version, sizeof(version), f);
    char *paren_pos = strchr(version, '(');
    *paren_pos = '\0';
    pclose(f);

    // Print date in center
	char *date = execute_system_command("date");

    struct winsize w1;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w1);
    int terminal_width1 = w1.ws_col;
    int length1 = strlen(date);
    int left_padding1 = (terminal_width1 - length1) / 2;

    for (int i = 0; i < left_padding1; i++) {
        printf(" ");
    }

    printf("%s", date);

    // Print host and username in center
    char hostname[200];
    char *username = getlogin();
    gethostname(hostname, sizeof(hostname));

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int terminal_width = w.ws_col;
    int length = strlen(username) + strlen(hostname) + 1;
    int left_padding = (terminal_width - length) / 2;

    for (int i = 0; i < left_padding; i++) {
		printf(" ");
    }

    printf("%s@%s\n", username, hostname);

    // Memory & RAM
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGE_SIZE);
    struct statvfs buf;
    statvfs("/", &buf);

    long total_ram = pages * page_size;
    double ram_gb = total_ram/1073741824;
    double ram_round = round(ram_gb * 10) / 10;

    unsigned long long total_space = buf.f_frsize * buf.f_blocks;
    double mem_gb = total_space/1073741824;
    double mem_round = round(mem_gb * 10) / 10;

	// APPLE
  	printf("\033[1;32m");
    printf("\n\t\t    'c.");
	printf("\033[0m");

	printf("\033[0;37m");
	printf("     			OS: ");
	printf("\033[0m");
	printf("%s %s\n", unameData.sysname, kernel_version);
	free(kernel_version);
	printf("\033[1;32m");

    printf("\t\t,xNMM.");

	printf("\033[0;37m");
	printf("     			Architecture: ");
	printf("\033[0m");
	printf("%s\n", unameData.machine);
	printf("\033[1;32m");

    printf("\t      .OMMMMo");

	printf("\033[0;37m");
	printf("     			CPU: ");
	printf("\033[0m");
	printf("%s\n", cpu);
	printf("\033[1;32m");

    printf("\t      OMMM0");

	printf("\033[0;37m");
	printf("     			Shell: ");
	printf("\033[0m");
	printf("%s\n", version);
	printf("\033[1;32m");

    printf("      .;loddo:' loolloddol;.");

	printf("\033[0;37m");
	printf("     		RAM: ");
	printf("\033[0m");
	printf("%.1f ", ram_round);
	printf("\033[0;37m");
	printf("GB\n");
	printf("\033[1;32m");

    printf("    cKMMMMMMMMMMNWMMMMMMMMMM0:");

	printf("\033[0;37m");
	printf("     		Storage: ");
	printf("\033[0m");
	printf("%.1f ", mem_round);
	printf("\033[0;37m");
	printf("GB\n");
	printf("\033[1;32m");

	printf("\033[1;33m");
	printf("  .KMMMMMMMMMMMMMMMMMMMMMMMWd.\n");
	printf("  XKMMMMMMMMMMMMMMMMMMMMMMX.\n");
	printf("\033[1;31m");
	printf(" ;MMMMMMMMMMMMMMMMMMMMMMMM:\n");
	printf(" :MMMMMMMMMMMMMMMMMMMMMMMM:\n");
	printf(" .MMMMMMMMMMMMMMMMMMMMMMMMX.\n");
	printf("  kMMMMMMMMMMMMMMMMMMMMMMMWd.\n");
	printf("\033[0m");
	printf("\033[1;35m");
	printf("  .XMMMMMMMMMMMMMMMMMMMMMMMMMk\n");
	printf("   .XMMMMMMMMMMMMMMMMMMMMMMK.\n");
	printf("\033[0m");
	printf("\033[1;34m");
	printf("     kMMMMMMMMMMMMMMMMMMMMMd\n");
	printf("      ;KMMMMMMMWXXWMMMMMMMk.\n");
	printf("        .cooc,.    .,coo:.\n\n");
	printf("\033[0m");
}
