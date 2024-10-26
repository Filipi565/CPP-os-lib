<h1>os::path::exists</h1>
<h2>Syntax</h2>

```C++
int os::path::exists(
    const char *path,
    bool follow_symlinks = true
);
```

<h2>Parameters</h2>

`path`

A string representing the path to check.

`follow_symlinks`

A boolean indicating whether to follow symbolic links when checking the existence of the path. Default value is true.

<h2>Return value</h2>

returns true if the path exists, false overwise
