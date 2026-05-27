# CPPtest — Agent Guide

## Repo structure

- **Monorepo of ~25 independent C++ console applications**, each in its own directory with a `*.vcxproj` and a `main()`.
- **No `.sln` file.** Open or build projects individually.
- **No cross-project dependencies**, no libraries, no shared code.
- **No test framework, no CI for C++.** The only workflow (`.github/workflows/opencode.yml`) is for the AI assistant on issue/PR comments.

## Build

- **Toolchain:** Visual Studio 2022 (platform toolset `v145`), C++20 (`stdcpp20`), MSBuild.
- **Configurations:** Debug/Release, platforms Win32/x64.
- **Build from command line:**
  ```
  msbuild Avatar\Avatar.vcxproj
  msbuild Avatar\Avatar.vcxproj /p:Configuration=Release /p:Platform=x64
  ```
- **No Makefile, CMake, vcpkg, or conan** — MSBuild is the only build system.

## Code conventions

- `using namespace std;` is used in every file (do not introduce `std::` prefixes).
- Member initializer lists and in-class definitions are both used; match adjacent code.
- Comments and UI strings are in Chinese.

## Notable configs

- `.nezha/config.toml` — Nezha AI agent config (alternative to OpenCode).
- `.writerHelper/mcp/setting.json` — WriterHelper VS Code extension timestamp (not actionable).
- `.vscode/settings.json` — Editor wrapping settings for WriterHelper.
