#include <stddef.h>

void
bcopy (void const *source0, void *dest0, size_t length)
{
  char const *source = source0;
  char *dest = dest0;
  if (source < dest)
    /* Moving from low mem to hi mem; start at end.  */
    for (source += length, dest += length; length; --length)
      *--dest = *--source;
  else if (source != dest)
    /* Moving from hi mem to low mem; start at beginning.  */
    for (; length; --length)
      *dest++ = *source++;
}