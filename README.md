
**raudio_sdl: An SDL2-Powered Fork of the raudio Library by raysan5**

`raudio_sdl` is an enhanced version of the `raudio` library, initially used in the `raylib` library [raylib](https://github.com/raysan5/raylib) as its internal audio module. While `raudio` offers the same audio functionality as `raylib`, `raudio_sdl` employs a SDL2-powered backend for audio playback. This enables audio playback on platforms not supported by `raudio`, such as the Nintendo Switch.

<br>

## features

 - Utilizes SDL2 as the backend for audio output on platforms not supported by `raudio`
 - Simplifies `miniaudio` usage exposing only basic functionality
 - Audio formats supported: `.wav`, `.qoa`, `.ogg`, `.mp3`, `.flac`, `.xm`, `.mod`
 - Select desired input formats at compilation time
 - Load and play audio, static or streamed modes
 - Support for plugable audio effects with callbacks

## usage

SDL2 is statically linked by default. For usage example, it's recommended to check the provided [`examples`](examples).

## license

`raudio` is licensed under an unmodified zlib/libpng license, which is an OSI-certified, BSD-like license that allows static linking with closed source software. Check [LICENSE](LICENSE) for further details.