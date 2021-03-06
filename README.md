# tophat

Tophat is a 2d game engine focused on minimalism and not taking power away from the user. Although it is made in c, you can make games using [umka](https://github.com/vtereshkov/umka-lang) a language inspired by go, that makes your gamedev easier. It currently supports linux and windows with web, android and raspberry pi support on the way. You can also visit the [discord server](https://discord.gg/PcT7cn59h9).

## features

- easy to use
- very lightweight
- both high-level abstractions like entities or tilemaps and low-level drawing using rawdraw.um
- collisions between raycasts, polygons and tilemaps (tilemap v raycast not implemented yet)
- minimalist ui framework
- automatic scaling - your games look the same no matter the resolution
- great cli tool for linux

## getting started

If you just want to see, how a game made using tophat looks like, you can find some in the `examples` folder.
If you like the engine and want to get started, read the [getting started article](https://github.com/marekmaskarinec/tophat/tree/main/doc/getting-started.md).
Documentation for all umka modules can be found in the [doc](https://github.com/marekmaskarinec/tophat/tree/main/doc) folder.
C documentation coming soon.

## games made with tophat

Aside from examples, I have made two jam games one is called [RAIDER](https://maskarinec.itch.io/RAIDER), but it was made a long time ago (before the v0.1 release), so some things
may not be done the same as they should be done now. Another one is [logs together](https://maskarinec.itch.io/logs-together). It is much newer than raider, but due
to the time constraint, it isn't written well.
If you know/have made a game in tophat, don't hesitate and make a pr to add it here.

## build instructions

### deps:
  - compiler - gcc, tcc and clang work. I didn't test any others.
  - libGL headers
  - libX11 headers for linux build
 
...

- `make deps` - downloads all submodules and libraries and builds umka
- `make run` - to build without optimizations and embedding + run
- `make install` - build and install, so you can test on existing projects
- `make build` - release build
- `make wbuild` - build for windows
- `make package` - creates a package, that can be installed using linux shell tool
- `make win-package` - same as above, but is makes a windows package

## todo

- tranparency on images
- navigation on tilemaps
- `move_and_slide`-like function
- convert backend to reals and allow for pixel imperfect movement
- physics engine
- embedding of user files
- web build
- auto tile

## special thanks

Here are people, who made a library, that is really important to tophat, or helped me with making tophat (or both).

- [vtereshkov](https://github.com/vtereshkov) - for creating [umka](https://github.com/vtereshkov/umka-lang).
- [cnlohr](https://github.com/cnlohr) - for creating rawdraw
- [avivbeeri](https://github.com/avivbeeri) - for creating dome engine (my inspiration) and helping me in the early days of the engine
- [prokoprandacek](https://github.com/prokoprandacek) - for his contributions
