<h1>os::listdir</h1>
<h2>Syntax</h2>

```C++
std::vector<std::string>
os::listdir(
    const char *path
);
```

<h2>Parameters</h2>

`path`

The path to the directory.

<h2>Return value</h2>

A vector of strings containing the names of all files and directories in the specified directory.