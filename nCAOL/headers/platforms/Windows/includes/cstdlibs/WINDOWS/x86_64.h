#ifndef NIGMA_CAOL_PLATFORMS_OS_INCLUDES_CSTDLIB_ARCH_H
#define NIGMA_CAOL_PLATFORMS_OS_INCLUDES_CSTDLIB_ARCH_H

#include "../../../../../specifics/interfaces.h"

//System-specific C standard headers.
#if ((caolSpecsCSTD(NCAOL_CURRENT_STD_ID) == caolSpecsCSTD(NCAOL_STD_ID_C89)) || \
     (caolSpecsCSTD(NCAOL_CURRENT_STD_ID) == caolSpecsCSTD(NCAOL_STD_ID_C90))    \
    )
    #include <assert.h>
    #include <signal.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <locale.h>
    #include <stdarg.h>
    #include <string.h>
    #include <errno.h>
    #include <math.h>
    #include <stddef.h>
    #include <time.h>
    #include <float.h>
    #include <setjmp.h>
    #include <stdio.h>
#elif ((caolSpecsCSTD(NCAOL_CURRENT_STD_ID) == caolSpecsCSTD(NCAOL_STD_ID_C94)) || \
       (caolSpecsCSTD(NCAOL_CURRENT_STD_ID) == caolSpecsCSTD(NCAOL_STD_ID_C95))    \
    )
    #include <assert.h>
    #include <signal.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <locale.h>
    #include <stdarg.h>
    #include <string.h>
    #include <errno.h>
    #include <math.h>
    #include <stddef.h>
    #include <time.h>
    #include <float.h>
    #include <setjmp.h>
    #include <stdio.h>
    #include <iso646.h>
    #include <wchar.h>
    #include <wctype.h>
#elif (caolSpecsCSTD(NCAOL_CURRENT_STD_ID) == caolSpecsCSTD(NCAOL_STD_ID_C99))
    #include <assert.h>
    #include <signal.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <locale.h>
    #include <stdarg.h>
    #include <string.h>
    #include <errno.h>
    #include <math.h>
    #include <stddef.h>
    #include <time.h>
    #include <float.h>
    #include <setjmp.h>
    #include <stdio.h>
    #include <iso646.h>
    #include <wchar.h>
    #include <wctype.h>
    #include <complex.h>
    #include <inttypes.h>
    #include <stdint.h>
    #include <tgmath.h>
    #include <fenv.h>
    #include <stdbool.h>
#elif ((caolSpecsCSTD(NCAOL_CURRENT_STD_ID) == caolSpecsCSTD(NCAOL_STD_ID_C11)) || \
       (caolSpecsCSTD(NCAOL_CURRENT_STD_ID) == caolSpecsCSTD(NCAOL_STD_ID_C17)) || \
       (caolSpecsCSTD(NCAOL_CURRENT_STD_ID) == caolSpecsCSTD(NCAOL_STD_ID_C18))    \
    )
    #include <assert.h>
    #include <signal.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <locale.h>
    #include <stdarg.h>
    #include <string.h>
    #include <errno.h>
    #include <math.h>
    #include <stddef.h>
    #include <time.h>
    #include <float.h>
    #include <setjmp.h>
    #include <stdio.h>
    #include <iso646.h>
    #include <wchar.h>
    #include <wctype.h>
    #include <complex.h>
    #include <inttypes.h>
    #include <stdint.h>
    #include <tgmath.h>
    #include <fenv.h>
    #include <stdbool.h>
    #include <stdalign.h>
    #include <stdatomic.h>
    #include <stdnoreturn.h>
    //#include <threads.h>
    #include <uchar.h>
#elif (caolSpecsCSTD(NCAOL_CURRENT_STD_ID) == caolSpecsCSTD(NCAOL_STD_ID_C23))
    #include <assert.h>
    #include <signal.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <locale.h>
    #include <stdarg.h>
    #include <string.h>
    #include <errno.h>
    #include <math.h>
    #include <stddef.h>
    #include <time.h>
    #include <float.h>
    #include <setjmp.h>
    #include <stdio.h>
    #include <iso646.h>
    #include <wchar.h>
    #include <wctype.h>
    #include <complex.h>
    #include <inttypes.h>
    #include <stdint.h>
    #include <tgmath.h>
    #include <fenv.h>
    #include <stdbool.h>
    #include <stdalign.h>
    #include <stdatomic.h>
    #include <stdnoreturn.h>
    //#include <threads.h>
    #include <uchar.h>
    #include <stdbit.h>
    #include <stdckdint.h>
#endif


#endif
