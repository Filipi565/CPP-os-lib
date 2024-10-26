<h1>os::path::is_file</h1>
<h2>Syntax</h2>

```C++
bool os::path::is_file(
    const char *path,
    bool follow_symlinks = true
);
```

<h2>Parameters</h2>

`path`

The path to check

`follow_symlinks`

A boolean indicating whether to follow symbolic
links when checking if the path is a regular file.
Default value is true.

<h2>Return value</h2>

returns true if the path exists and the path is a regular file, false overwise
