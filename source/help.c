#include "help.h"
#include "common.h"
#include "pa.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void real_usage (void);
static void ayuda_document (void);

static void ayuda_readonly (void);
static void ayuda_help (void);

void help_usage_help (const char *with)
{
    if (with == NULL) { real_usage(); return; }
    const size_t L = strlen(with);

    if (!strncmp(with, "document", L))      { ayuda_document(); }
    else if (!strncmp(with, "readonly", L)) { ayuda_readonly(); }
    else if (!strncmp(with, "help", L))     { ayuda_help(); }
    else                                    { real_usage(); }
    exit(EXIT_SUCCESS);
}

void help_undef_flag (const char *undef)
{
    static const char *nondef =
    "\n"
    "  Parfait - Undefined flag `%s`\n\n"
    "  Error: Unrecognized flag. Execution cannot continue.\n"
    "  Did you mean one of the following?\n\n";
    fprintf(stderr, nondef, undef);

    for (u8_t i = 0; pa_similar[i].flag; i++)
    {
        fprintf(stderr, "    ~ \x1b[%dm%s\x1b[0m\n", pa_similar[i].fav ? 1 : 0, pa_similar[i].flag);
    }
    fprintf(stderr, "\n");
    exit(EXIT_FAILURE);
}

void help_missed_arg (void)
{
    static const char *missed =
    "\n"
    "  Parfait - Missing argument for `%s`\n\n"
    "  This flag requires an argument.\n"
    "  For more information, type:\n"
    "    $ pf --help %s\n"
    "\n";
    fprintf(stderr, missed, pa_flagname, pa_flagname);
    exit(EXIT_FAILURE);
}

void help_nonsense (const char *what)
{
    static const char *nonsense =
    "\n"
    "  Parfait - Invalid input: `%s`\n\n"
    "  Unrecognized command or argument.\n"
    "  For correct usage, type:\n"
    "    $ pf --help\n"
    "\n";
    fprintf(stderr, nonsense, what);
    exit(EXIT_FAILURE);
}

static void real_usage (void)
{
    static const char *usage =
    "\n"
    "  Parfait - Spreadsheet Engine (Compiled: %s %s)\n\n"
    "  Usage:\n"
    "    pf [options] [document]\n"
    "    pf [options] -D <document>\n"
    a    pf -H [flag]\n\n"
    "  Options:\n"
    "    -D, --document <file>  Load specified spreadsheet file\n"
    "    -R, --readonly         Open in read-only mode (modifiable at runtime)\n"
    "    -H, --help [flag]      Show program usage or specific flag usage\n"
    "\n";
    printf(usage, __DATE__, __TIME__);
}

static void ayuda_document (void)
{
    static const char *ayuda =
    "\n"
    "  Parfait - Document Flag (-D, --document)\n\n"
    "  Description:\n"
    "    Specifies the spreadsheet file to load. If omitted, a new blank document\n"
    "    is created automatically.\n\n"
    "  Example:\n"
    "    $ pf --document mysheet.pf\n"
    "    $ pf -D mysheet.pf\n"
    "\n";
    printf("%s", ayuda);
}

static void ayuda_readonly (void)
{
    static const char *ayuda =
    "\n"
    "  Parfait - Read-Only Flag (-R, --readonly)\n\n"
    "  Description:\n"
    "    Opens the spreadsheet in read-only mode. This setting can be changed\n"
    "    at runtime.\n\n"
    "  Example:\n"
    "    $ pf --readonly\n"
    "    $ pf -R\n"
    "\n";
    printf("%s", ayuda);
}

static void ayuda_help (void)
{
    static const char *ayuda =
    "\n"
    "  Parfait - Help Flag (-H, --help)\n\n"
    "  Description:\n"
    "    Displays general program usage. If followed by a flag name, shows\n"
    "    specific usage information for that flag.\n\n"
    "  Example:\n"
    "    $ pf --help document\n"
    "    $ pf -H help\n"
    "    $ pf -H\n"
    "\n";
    printf("%s", ayuda);
}
