# C++ os lib

* Library inspired in [python's](https://python.org) [os](https://github.com/python/cpython/blob/3.12/Lib/os.py) module:

# Topics
* <a href="./docs/README.md">Documentation</a>
* <a href="#Platforms">Platforms</a>
    * [GNU Linux & Mac](#Linux)
    * [MSVC Windows](#Windows)

# Platforms

<h1 id="Linux">GNU Linux</h1>

* <h3>Install the required programs: <a href="https://git-scm.com/downloads">git</a>, <a href="https://cmake.org/download/">cmake</a> and <a href="https://www.gnu.org/software/make/">GNU make</a></h3>

* <h3>Clone the repository</h3>

```bash
git clone https://github.com/Filipi565/CPP-os-lib.git --branch stable
```

* <h3>Enter the project Directory</h3>

```bash
cd CPP-os-lib
```

* <h3>Create and select a build directory</h3>

```bash
mkdir build # the name is not relevant
cd build
```

* <h3>Run the cmake command:</h3>

```bash
cmake .. # configure to build the lirary as shared object
```

<h4>If you want to build a static version of the lib just run:</h4>

```bash
cmake .. -DLIBTYPE=STATIC # configure to build the lirary as static object
```

* <h3>Build and install the library</h3>

```bash
make
sudo make install
```

* <h3>Update your libraries</h3>

```bash
sudo ldconfig
```

<h1 id="Windows">MSVC Windows</h1>

<h3>You may prefer to download a <a href="https://github.com/Filipi565/CPP-os-lib/releases">release</a>, but if you still want to build yourself, follow the steps:</h3>

* <h3>Install the required program: <a href="https://cmake.org/download/">cmake</a><h3>

*  <h3>Clone the repository</h3>

```bash
git clone https://github.com/Filipi565/CPP-os-lib.git --branch stable
```

* <h3>Enter the project Directory</h3>

```bash
cd CPP-os-lib
```

* <h3>Create and select a build directory</h3>

```bash
mkdir build # the name is not relevant
cd build
```

* <h3>Run the cmake command:</h3>

```bash
cmake .. # configure to build the lirary as shared object
```

<h4>If you want to build a static version of the lib just run:</h4>

```bash
cmake .. -DLIBTYPE=STATIC # configure to build the lirary as static object
```

* <h3>Open the Visual Studio .sln project</h3>

* <h3>Go to build -> Build Solution</h3>