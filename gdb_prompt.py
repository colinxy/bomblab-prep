
import gdb


# reference
# http://agentzh.org/misc/code/gdb/python/lib/gdb/command/prompt.py.html
class _ExtendedPrompt(gdb.Parameter):

    """Set the extended prompt.

    Usage: set extended-prompt VALUE

    Substitutions are applied to VALUE to compute the real prompt.

    The currently defined substitutions are:

    """
    # Add the prompt library's dynamically generated help to the
    # __doc__ string.
    __doc__ = __doc__ + gdb.prompt.prompt_help()

    set_doc = "Set the extended prompt."
    show_doc = "Show the extended prompt."

    def __init__(self):
        super(_ExtendedPrompt, self).__init__("extended-prompt",
                                              gdb.COMMAND_SUPPORT,
                                              gdb.PARAM_STRING_NOESCAPE)
        self.prompt = None
        self.hook_set = False

    def get_show_string(self, pvalue):
        if self.prompt is not None:
            return "The extended prompt is: " + self.prompt
        else:
            return "The extended prompt is not set."

    def get_set_string(self):
        if not self.hook_set:
            gdb.prompt_hook = self.before_prompt_hook
            self.hook_set = True
        return ""

    def before_prompt_hook(self, current):
        try:
            frame = gdb.selected_frame()
            self.prompt = frame.name().encode("ascii", "replace") + " > "
            return self.prompt
        except gdb.error:
            return "(gdb) "

_ExtendedPrompt().get_set_string()


class ContinueBomb(gdb.Command):
    """custom continue for bomblab

    thwart continuing when in explode_bomb
    """

    def __init__(self):
        super(ContinueBomb, self).__init__(
            "cb",
            gdb.COMMAND_USER,
        )

    def invoke(self, arg, from_tty):
        if gdb.selected_frame().name() == "explode_bomb":
            print(
                "*********************************\n"
                "*                               *\n"
                "* You have entered explode_bomb *\n"
                "*                               *\n"
                "*********************************\n"
            )
            gdb.execute("kill")
        else:
            gdb.execute("continue")

ContinueBomb()
