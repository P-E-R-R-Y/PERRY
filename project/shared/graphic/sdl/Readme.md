It's Graphics3

imodul 3d herit du Imodel 2d

# Develop

## includes are defined here for more information

`https://github.com/libsdl-org/SDL_image/blob/release-2.8.2/examples/showimage.c`

in macos I ran into this issue:

```sh
In file included from /Users/perrychouteau/Documents/GitHub/PERRY/project/build/_deps/sdl2_mixer-src/src/codecs/music_opus.c:34:
/opt/homebrew/include/opus/opusfile.h:110:11: error: 'opus_multistream.h' file not found with <angled> include; use "quotes" instead
  110 | # include <opus_multistream.h>
      |           ^~~~~~~~~~~~~~~~~~~~
      |           "opus_multistream.h"
1 error generated.
make[2]: *** [_deps/sdl2_mixer-build/CMakeFiles/SDL2_mixer.dir/src/codecs/music_opus.c.o] Error 1
make[1]: *** [_deps/sdl2_mixer-build/CMakeFiles/SDL2_mixer.dir/all] Error 2
make: *** [all] Error 2
```

fixed will editing this file `.../project/build/_deps/sdl2_mixer-src/VisualC/external/include/opus/opus.h`