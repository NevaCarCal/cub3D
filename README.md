*This project has been created as part of the 42 curriculum by brimarti, ncarrera.*

## Description

cub3D is a real-time raycasting engine written in C, inspired by the classic Wolfenstein 3D. It renders a 3D first-person view from a 2D map using the DDA (Digital Differential Analyzer) algorithm, built on top of the MinilibX graphics library.

### Features

- **Raycasting engine**: DDA-based wall detection with perpendicular distance correction to avoid fisheye distortion.
- **Textured walls**: Four wall textures (North, South, West, East) mapped according to the hit side and wall direction.
- **Solid floor and ceiling**: Configurable solid colors for the sky and ground.
- **Player movement**: Smooth collision-aware movement with wall sliding.
- **Rotation**: Arrow-key rotation combined with forward/backward strafing via `dir_x` / `dir_y` vectors and a camera `plane_x` / `plane_y` vector.
- **Map parsing**: Validates `.cub` map files for correct syntax, closed walls, and exactly one player spawn.
- **Error handling**: Custom error system with clean resource deallocation on failure.

### Technical choices

- **Graphics**: MinilibX Linux (X11/MLX).
- **Math**: `math.h` for trigonometric functions, `fabs`, and floating-point precision.
- **Map storage**: NULL-terminated array of strings (`char **`), parsed line-by-line with `get_next_line`.
- **Rendering**: Per-column wall stretching with texture coordinate interpolation (`tex_step` / `tex_pos`) clamped to valid texture bounds.

## Instructions

### Compilation

```bash
make
```

The Makefile will automatically build the MinilibX Linux library (`minilibx-linux`) and the custom `ft_printf` libraryif they are present, then compile all source files into the `cub3D` binary.

### Execution

```bash
./cub3D maps/basic.cub
```

or

```bash
./cub3D maps/test1000.cub
```

### Controls

| Key | Action |
|-----|--------|
| W / ↑ | Move forward |
| S / ↓ | Move backward |
| A | Strafe left |
| D | Strafe right |
| ← / → | Rotate left / right |
| ESC | Quit |

### Map format

Maps are `.cub` files containing:

```
NO path/to/north.xpm
SO path/to/south.xpm
WE path/to/west.xpm
EA path/to/east.xpm

F R,G,B
C R,G,B

1111111111
1000000001
1000001001
10001N0001
1111111111
```

- Four texture paths (`NO`, `SO`, `WE`, `EA`) must be valid XPM files.
- `F` sets floor color, `C` sets ceiling color (RGB 0-255 separated by commas).
- The map must be rectangular, closed by walls (`1`), and contain exactly one player spawn (`N`, `S`, `E`, or `W`).

### Cleaning

```bash
make clean    # removes object files
make fclean   # removes object files + binary
make re       # clean + rebuild
```

## Resources

- [Ray Casting (C++) – Ismail Assil](https://ismailassil.medium.com/ray-casting-c-8bfae2c2fc13) — Article explaining the raycasting algorithm, DDA steps, and wall rendering math.
- [Let's Make a Raycaster! – YouTube playlist by Ckladmlo](https://www.youtube.com/watch?v=gYRrGTC7GtA&list=PLCWsH9Tj9oWyDM4W43VMj5yo2PdyYMGst) — Video tutorial covering pixel drawing, player movement, and texture mapping from scratch.

## AI Usage

AI was used during development for the following tasks:

- **Research and algorithm validation**: Checking the correctness of the DDA implementation, particularly the perpendicular distance formula and fish-eye correction.
- **Debugging edge cases**: Identifying potential integer truncation bugs in wall height calculation (e.g., `line_height` becoming zero when the distance exceeds window height) and proposing safe integer clamps.
- **Code architecture feedback**: Reviewing file organization, function granularity, and suggesting improvements for readability and norm compliance.
- **Documentation**: Assisting with README composition and technical explanations.

AI was not used to generate gameplay logic, core rendering code, or map parsing logic from scratch; all engine code was written manually and iteratively tested.
