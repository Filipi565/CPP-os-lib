# C++ os lib

* Library inspired in python [os](https://github.com/python/cpython/blob/3.12/Lib/os.py) module:

# Topics
* <a href="#Docs">Documentation</a>
* <a href="#Building">How to Build</a>

# Docs
* <h2>os::getcwd</h2>
<h3>Syntax</h3>

```C++
int os::getcwd(
    char *buffer,
    size_t buffer_size
);
```

<h3>Parameters</h3>

`buffer`

Storage location for the cwd.

`buffer_size`

The maximum length of the path in characters.

<h3>Return value</h3>

returns 0 if successfully, 1 overwise.