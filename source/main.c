#include "common.h"
#include "help.h"
#include "pa.h"

#include <string.h>

#define INTERN_N_FLAGS  3

static void parse_execution_arguments (struct program*, const int, char**);
static void welcome_message (void);

int main (int argc, char **argv)
{
    struct program P;
    memset(&P, 0, sizeof(P));

    parse_execution_arguments(&P, argc, argv);
    /* TODO;
     * 1. Deal with echo and cbreak
     * 2. Set up signals
     * */

    if (P.args.filename == NULL)
    {
        /* TODO: Create new blank document */
    }
    else
    {
        /* TODO: Load document */
    }

    return 0;
}

static void parse_execution_arguments (struct program *p, const int argc, char **argv)
{
    /* NOTE: If a new option is added make sure to
     * increase the value of `INTERN_N_FLAGS` by one. */
    static const struct pa_option opts[] = {
        {"document", 'D', pa_takes_arg},
        {"readonly", 'R', pa_noway_arg},
        {"help",     'H', pa_might_arg},
    };

    u16_t at;
    while (true)
    {
        const pa_t ret = pa_get(argc, argv, &at, INTERN_N_FLAGS, opts);
        if (ret == pa_ret_cest_fini) { break; }

        switch (ret)
        {
            case 'D': case pa_ret_pos_arg: { p->args.filename = pa_argument; break; }
            case 'R':                      { p->args.readonly = true; break; }
            case 'H':                      { help_usage_help(pa_argument); break; }
            case pa_ret_undef_flag:        { help_undef_flag(argv[at]); break; }
            case pa_ret_missed_arg:        { help_missed_arg(); break; }
            case pa_ret_nonsense:          { help_nonsense(argv[at]); break; }
        }
    }
}

static void welcome_message (void)
{

}
