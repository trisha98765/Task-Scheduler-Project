**Note:** This only works on macOS and Linux.

To use `valgrind.sh`, use the following command from the project root:

```bash
testing/valgrind.sh
```

This will create a folder called "test-logs" containing the valgrind outputs for each input file.

If you get a "permission denied" error, try running

```bash
chmod +x testing/valgrind.sh
```
