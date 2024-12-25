# George Michael Lyric Quiz
A fill-in-the blanks lyric game featuring only George Michael songs, written in C with Clay and Raylib.
Made as a christmas gift for someone special :)

## Requirements
- Raylib (`brew install raylib pkgconfig`)
- GCC (`brew install gcc`)
- GNU Make (`brew install make`)
- CMake (`brew install cmake`)

### Building
Use:
```bash
make
```

Or, to build and run:
```bash
make run
```

To clean up build artefacts, including the output binary:
```bash
make clean
```

### Installing
Use:
```bash
make install
```

### Uninstalling
use:
```bash
make uninstall
```

## Usage
If installed, use `gm-quiz` to launch.

Key bindings:
- `Ctrl + R` - Restart game with a new lyric.
- `Ctrl + L` - Clear input box.
- `Ctrl + D` - Open Clay debug menu.
- `Enter` - Submit word!
- `Ctrl + Q` - Quit.
