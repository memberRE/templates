#include <signal.h>
#include <unistd.h>
#include "xil_types.h"

#ifdef __cplusplus
extern "C" {
	__attribute__((weak)) s32 _kill(s32 pid, s32 sig);
}
#endif

/*
 * kill -- go out via exit...
 */

__attribute__((weak)) s32 kill(s32 pid, s32 sig)
{
  if(pid == 1) {
    _exit(sig);
  }
  return 0;
}

__attribute__((weak)) s32 _kill(s32 pid, s32 sig)
{
  if(pid == 1) {
    _exit(sig);
  }
  return 0;
}