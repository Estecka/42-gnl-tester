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
