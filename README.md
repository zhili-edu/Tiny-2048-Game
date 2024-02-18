# Tiny 2048 Game

一个简单的由C++语言构成的2048游戏，仅支持Windows操作系统。

## 如何运行

在 Releases 中下载单一 C++ 源码，使用传统 Dev-cpp IDE进行编译即可运行。或使用命令行、或使用其他IDE对其进行编译即可运行。

## 如何开发

下载项目文件，并保证环境变量中存在`g++`, `cmake`软件。

- `src` 文件夹中存放被拆解的代码。
- `tests` 文件夹中存放单元测试的代码。
- `external` 文件夹中存放单元测试使用到的 Catch2 源码与 ChatGPT-4.0 生成的小工具。

编译仅需在目录中执行：

```bash
mkdir build && cd build
cmake ..
make
```