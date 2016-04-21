
import gdb


class ContinueBomb(gdb.Command):
    """custom continue for bomblab

    Invoke with cb.

    Give you a heads-up when you are in function explode_bomb,
    by thwarting continue when in explode_bomb.

    Notice however it might not be able to set a breakpoint
    at the function explode_bomb, you will have to set a breakpoint
    at function explode_bomb by yourself.
    """

    def __init__(self):
        super(ContinueBomb, self).__init__("cb",
                                           gdb.COMMAND_USER)
        gdb.execute("break explode_bomb")

    def invoke(self, arg, from_tty):
        try:
            if gdb.selected_frame().name() == "explode_bomb":
                print("\033[0;31m"
                      "*********************************\n"
                      "*                               *\n"
                      "* You have entered explode_bomb *\n"
                      "*                               *\n"
                      "*********************************"
                      "\033[0m\n")
                gdb.execute("kill")
            else:
                gdb.execute("continue")
        except gdb.error as err:
            print(err.message)

ContinueBomb()
