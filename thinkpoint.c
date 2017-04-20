#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>

int
write_config (char * path, int config)
{
    FILE * fp = fopen (path, "w");

    if (fp == NULL) {
        perror (path);
        exit (errno);
    }

    if(fprintf (fp, "%d", config) > 0) {
        printf ("Wrote %d to %s\n", config, path);
        fclose (fp);
        return 0;
    } else {
        perror (path);
        fclose (fp);
        exit (errno);
    }
}

int
main (int argc, char *argv[], char * envp[])
{
    envp = 0; /* blocks IFS attack on non-bash shells */

    write_config ("/sys/devices/platform/i8042/serio1/serio2/sensitivity", 240);
    write_config ("/sys/devices/platform/i8042/serio1/serio2/inertia", 3);
    write_config ("/sys/devices/platform/i8042/serio1/serio2/speed", 49);
    write_config ("/sys/devices/platform/i8042/serio1/serio2/thresh", 8);
    write_config ("/sys/devices/platform/i8042/serio1/serio2/press_to_select", 1);
    write_config ("/sys/devices/platform/i8042/serio1/serio2/skipback", 1);

    perror (argv[0]);
    return errno;
}
