# 42-gnl-tester
Personal makeshift tester for 42's get_next_line project.

### Usage
Clone into your project's folder. **Use the `--recursive` option for cloning.**
```sh
git clone --recursive https://github.com/Estecka/42-gnl-tester.git gnl-tester
```

Run `make` in the tester's folder then use :
- `./test.out` with no argument to test using the standard entry. (Then use CTRL+D to send the End of File.)
- `./test.out <path>` to test by reading a given file.
- `./test.out <fd>` to test by reading an arbitrary file descriptor.

This tester does not really _validate_ your output, but helps _inspecting_ the results.
For each return of `get_next_line`, the tester will display in order: the return value of the function, the literal representation of the string, and the hex value of the string.
```
1|I am a line        | 49 20 61 6D 20 61 20 6C 69 6E 65 0D 00
1|I am another line  | 49 20 61 6D 20 61 6E 6F 74 68 65 72 20 6C 69 6E 65 0D 00
0|I am the last line | 49 20 61 6D 20 74 68 65 20 6C 61 73 74 20 6C 69 6E 65 0D 00
```
- The null terminator will be highlighted in **green** in the hexdump.
- If a `\n` slipped into your string, they'll be highlighted in **red** in the hex dump, and symbolized by a red `$` in the literal.
