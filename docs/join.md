<h1>os::path::join</h1>
<h2>Syntax</h2>

```C++
int os::path::join(
    char *buffer,
    size_t maxlength,
    const std::initializer_list<const char *> &parts
);
```

<h2>Parameters</h2>

`buffer`

Storage location for the joined path.

`maxlength`

The maximum length of the path in characters.

`parts`

A list of string to be joined.

<h2>Return value</h2>

returns 0 if successfully, 1 overwise.
