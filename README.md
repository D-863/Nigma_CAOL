# Nigma_CAOL
![CAOL_LOGO](caol_icon.png)

## (Currently in development.)
nCAOL is a C-based ***Cross-Architecture Operation Layer*** in any space, created to implement ***Operations*** across vast Subjects in various Forms and Layers, yet without paying any unnecessary runtime cost despite the utilized Architecture, OS, CSTDLIB, Compiler and Standard.

And for certain platforms that doesn't supply a standard C-based compilation system(*Ahem*, Windows), it acts like a central user-configurable source too fufill said compilation when installed from the platform-specific installer.\
So installers aren't packaged with identical compilation system copies, and hence escaping the usual bloat and decreasing download time.
\
\
\
It's also free for anyone, as in both Speech and Beer(Libre and Gratis, use it with freedom and without charge).

## Overview
In a lack of words, the goal with nCAOL is to provide a layer where the implementation of various ***Operations*** across vast Subjects is more computationally ***Omniversal***; Despite what instructions the underlying Architecture may provide..\
And as the '***Layer***' tier within the acronym may imply, this goal is fully fulfilled upon compilation or in certain cases bootstrapped-compilation.

This enables ***Applications & Modules*** on various layers to implement their Systems without worrying about what fundamental instruction's the Compiler or CSTDLIB does not fully expose(SIMD, sin, sqrt, etc) and the respective Syntax of each exposed instruction,\
or maybe even how to implement Higher-Level operations from various Subjects like Calculus, Linear Algebra, Geometric Algebra and so on.. If I ever implement such Higher-Level concepts in a seprate layer project.
\
\
\
***But that's certainly not all!***
\
\
\
As a consequence from the journey towards computational ***Omniversality***, nCAOL also implements generic interfaces that handle the specifics between realms, and how each realm influence each other and how all changes across versions; No more platform preprocessor-spaghetti, for example:
```c
//nCAOL's entry-header file, and everything is complete on the software side.
//Relative path depends to your project, not the system.
#include "include/nCAOL/headers/nCAOL.h"

#if (caolSpecsArch(NCAOL_CURRENT_ARCH_ID) == caolSpecsArch(PowerPC))
    //We are on a RISC class CPU, and specifically the PowerPC architecture!
#elif (caolSpecsArch(NCAOL_CURRENT_ARCH_ID) == caolSpecsArch(PowerPC64))
    //We are on a RISC class CPU, and specifically the PowerPC-64 architecture!
#endif
//And if someone finds a forgotten pre-define for either,
//then everyone benefit silently without a single change.
```
***Instead of this anxiety inducing BS:***
```c
//What ever platform-specific headers that provides these pre-defines..
//Which can suddenly change locations and all just over some neat possible configuration, by the way. :p
#include <...>
#include <...>
#include <...>

#if (defined(__ppc)         || \
     defined(__ppc__)       || \
     defined(__PPC__)       || \
     defined(__ppc64__)     || \
     defined(__PPC64__)     || \
     defined(__powerpc)     || \
     defined(__powerpc__)   || \
     defined(__POWERPC__)   || \
     defined(__powerpc64__) || \
     defined(_ARCH_PPC)     || \
     defined(_ARCH_PPC64)   || \
     defined(_M_PPC)           \
    )
    //Okay.. It's a PowerPC, and we know those CPUs are a RISC class type.. But what exact architecture?

    #if (defined(__ppc64__)     || \
         defined(__PPC64__)     || \
         defined(__powerpc64__) || \
         defined(_ARCH_PPC64)      \
        )
        //Ah, specifically the PowerPC-64 architecture it seems.
    #else
        //Ah, specifically the PowerPC architecture it seems.
    #endif
    //Hope we didn't misspell one of those 12+4 pre-defines.. -.-'

    //Wait- Did I forget one?
    //Oh well, obviously no user would *ever* occur upon that case.... Right?
#endif
```

> [!WARNING]
> There may be potentially a single requirement to ***Manually*** specify within 'enables.h', which is either the utilized OS **or** CSTDLIB; In a nutshell, it's respectively a nonstandard-path and self-included-define kind of problem that is beyond the Compiler's grasp.. **But**, if the respective identification of either has already been silently provided to the Compiler, then this paradox is resolved.

\
Wow, that's a lot of resolved Nightmares! Hopefully..

## Setup
```bash
git clone https://github.com/D-863/Nigma_CAOL.git
```
Currently, there really isn't a required setup.\
(But will likely change, to resolve the above WARNING and to enable Installation portability.)

As usual with my library projects, simply include the entry-header '[nCAOL.h](https://github.com/D-863/Nigma_CAOL/blob/main/nCAOL/headers/nCAOL.h)' after moving this project's 'nCAOL' directory into your own respective project.\
(For legal reasons, you should ***probably*** also move the '[LICENSE](https://github.com/D-863/Nigma_CAOL/blob/main/LICENSE)' file into the 'nCAOL' directory, or into a appropriate substitute.)

## Proof by diagnosis
While I obviously cannot go thru every 65 Operating Systems, on every 17 Architectures, with every compatible CSTDLIB and Compile for every C-Standard as a singular individual.. Especially seeing how some are *guaranteed* to be lost Software or Hardware..

I hope you personally exploring the available '[diagnosis](https://github.com/D-863/Nigma_CAOL/blob/main/diagnosis)' per tested platform is good enough proof for now, as nCOSA require this to be mature enough for the top platforms before further developement.

> [!NOTE]
> If your particular '[diagnosis](https://github.com/D-863/Nigma_CAOL/blob/main/diagnosis)' directory is missing your desired platform, then please download it from the latest [release](https://github.com/D-863/Nigma_CAOL/releases) and decompress it inside the directory, then simply follow the 'README.md' file which explains that platform's required execution path.\
> Some platforms may require heavy or multiple dependencies and hence, it would not only be impractical to package all of them within the nCAOL library itself, but also technically imply that they're under nCAOL's [LICENSE](https://github.com/D-863/Nigma_CAOL/blob/main/LICENSE)-Which they are certantly not.

# Crediting
While providing proper credits by either:
* My [Profile](https://github.com/D-863) by Name orIcon.
* This [Project](https://github.com/D-863/Nigma_CAOL) by Link or Name.
* The Website for all my work. (To be created)

within your own lovely home is very much appreciated seeing how I am just a singular pair of unknown hands:\
Such is certainly not **required** if it somehow becomes a burden! - I personally only mind if you found my work delightful as such is what makes it worth it.

Though if you did find the pie delightful or intriguing, then of course please do consider at least spreading the word so others may also enjoy it..\
Sharing is caring and words are powerful!

## QNA_Website
FUTURE_WEBSITE_FOR_DOCS_AND_QNA.

# MIT License
main/[LICENSE](https://github.com/D-863/Nigma_CAOL/blob/main/LICENSE)
