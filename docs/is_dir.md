<h1>os::path::is_dir</h1>
<h2>Syntax</h2>

```C++
int os::path::is_dir(
    const char *path,
    bool follow_symlinks = true
);
```

<h2>Parameters</h2>

`path`

The path to check

`follow_symlinks`

A boolean indicating whether to follow symbolic
links when checking if the path is a directory.
Default value is true.

<h2>Return value</h2>

returns true if the path exists and the path is a directory, false overwise
