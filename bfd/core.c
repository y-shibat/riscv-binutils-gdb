/*doc*
@section Core files
Buff output this facinating topic
*/

#include "sysdep.h"
#include "bfd.h"
#include "libbfd.h"

/** Some core file info commands */

/*proto*i bfd_core_file_failing_command
Returns a read-only string explaining what program was running when
it failed and produced the core file being read

*; PROTO(CONST char *, bfd_core_file_failing_command, (bfd *));
*/

CONST char *
DEFUN(bfd_core_file_failing_command,(abfd),
      bfd *abfd)
{
  if (abfd->format != bfd_core) {
    bfd_error = invalid_operation;
    return NULL;
  }
  return BFD_SEND (abfd, _core_file_failing_command, (abfd));
}

/*proto* bfd_core_file_failing_signal
Returns the signal number which caused the core dump which generated
the file the bfd is attatched to.

*; PROTO(int, bfd_core_file_failing_signal, (bfd *));
*/
int
bfd_core_file_failing_signal (abfd)
     bfd *abfd;
{
  if (abfd->format != bfd_core) {
    bfd_error = invalid_operation;
    return 0;
  }
  return BFD_SEND (abfd, _core_file_failing_signal, (abfd));
}


/*proto* core_file_matches_executable_p
Returns @code{true} if the core file attatched to @var{core_bfd} was
generated by a run of the executable file attatched to @var{exec_bfd},
or else @code{false}.
*; PROTO(boolean, core_file_matches_executable_p,
    (bfd *core_bfd, bfd *exec_bfd));
*/
boolean
core_file_matches_executable_p (core_bfd, exec_bfd)
     bfd *core_bfd, *exec_bfd;
{
  if ((core_bfd->format != bfd_core) || (exec_bfd->format != bfd_object)) {
    bfd_error = wrong_format;
    return false;
  }

  return BFD_SEND (core_bfd, _core_file_matches_executable_p, (core_bfd, exec_bfd));
}
