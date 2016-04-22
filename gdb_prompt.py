
import gdb


# reference
# http://agentzh.org/misc/code/gdb/python/lib/gdb/command/prompt.py.html
class ExtendedPrompt(gdb.Parameter):

    """Set the extended prompt.
    """
    # Add the prompt library's dynamically generated help to the
    # __doc__ string.
    __doc__ = __doc__ + gdb.prompt.prompt_help()

    set_doc = "Set the extended prompt."
    show_doc = "Show the extended prompt."

    def __init__(self):
        super(ExtendedPrompt, self).__init__("extended-prompt",
                                             gdb.COMMAND_SUPPORT,
                                             gdb.PARAM_STRING_NOESCAPE)
        self.prompt = None

    def get_show_string(self, pvalue):
        if self.prompt is not None:
            return "The extended prompt is: " + self.prompt
        else:
            return "The extended prompt is not set."

    def get_set_string(self):
        gdb.prompt_hook = self.before_prompt_hook
        return ""

    def before_prompt_hook(self, current):
        try:
            frame_name = gdb.selected_frame().name().\
                encode("ascii", "replace")

            if "bomb" in frame_name or "explode" in frame_name \
                    or "submit" in frame_name:  # red prompt
                frame_name = "\033[0;31m" + frame_name + "\033[0m"
            elif "phase" in frame_name:  # green prompt
                frame_name = "\033[0;32m" + frame_name + "\033[0m"
            else:               # yellow prompt
                frame_name = "\033[0;33m" + frame_name + "\033[0m"

            self.prompt = '(' + frame_name + ') > '
            return self.prompt
        except gdb.error:
            self.prompt = None
            return "(gdb) "
        except Exception:
            self.prompt = "(unknown function) "
            return self.prompt

ExtendedPrompt().get_set_string()
