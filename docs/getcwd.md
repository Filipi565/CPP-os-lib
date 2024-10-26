<h1>os::getcwd</h1>
<h2>Syntax</h2>

```C++
int os::getcwd(
    char *buffer,
    size_t maxlength
);
```

<h2>Parameters</h2>

`buffer`

Storage location for the cwd.

`maxlength`

The maximum length of the path in characters.

<h2>Return value</h2>

returns 0 if successfully, 1 overwise.
