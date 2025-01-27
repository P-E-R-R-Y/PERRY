# Doxygen

## Installation

- macos install `brew install doxygen`

## Config

- create doxyfile `doxygen -g`
- set name `PROJECT_NAME = "Name"`
- set version `PROJECT_NUM = "vX.X.X`
- 
- set brief `PROJECT_BRIEF = "brief"`
- set logo `PROJECT_LOGO = "path_to.."`

## Input

- set input directory `INPUT = "path/to/root"`
- file patterns `FILE_PATTERNS = *.h *.cpp`
- add subdirectories  `RECURSIVE = YES`
- Exclusion `EXCLUDE =` `EXCLUDE_SIMLINK = NO` `EXCLUDE_PATTERNS = */build/ */test/* */doc/*`
- main page `USE_MDFILE_AS_MAINPAGE = Readme.md`

## Output

- set output directory `OUTPUT_DIRECTORY = ./`
- set HTML output `GENERATE_HTML = YES` `HTML_OUTPUT = html`
- set LaTeX output `GENERATE_LATEX = NO` `LATEX_OUTPUT = latex`

## Documentation

- enable extraction of all entities `EXTRACT_ALL = YES`
- enable class diagrams `HAVE_DOT = YES`
- set dot path `DOT_PATH = /usr/local/bin/dot`