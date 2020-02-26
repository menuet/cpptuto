
# Minimum required software on Windows
- **Visual Studio**: the text editor and the Microsoft C++ compiler
- **Git**: the software which stores the history of your source files
- **CMake**: the build engine which builds your source files
- **vcpkg**: the package manager which downloads and builds the open-source third-parties libraries that your project depends on

# Install required software on Windows

## Install or Modify Visual Studio 2019 Community C++ Components
- In your browser, go to: https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=Community&rel=16
- Your browser should propose you to download the installer program "vs_community__.....exe"
- Save the file and click on it to start the installation or modification of Visual Studio 2019
- If you have already installed Visual Studio, click on "Modify" else click on "Install"
- In the tab "Workloads" ("Charges de travail"), select these items (or verify that they are already selected):
  - "Desktop Development in C++" ("Développement Desktop en C++")
  - "Linux Development in C++" ("Développement Linux en C++")
- In the tab "Individual components" ("Composants individuels"), select these items (or verify that they are already selected):
  - "C++ CMake tools for Linux" ("Outils C++ CMake pour Linux")
  - "C++ CMake tools for Windows" ("Outils C++ CMake pour Windows")
  - "C++ Address Sanitizer (experimental)"
  - "C++ Clang Tools for Windows" ("Outils C++ Clang pour Windows")
- In the tab "Linguistic Modules" ("Module linguistiques"), select these items (or verify that they are already selected):
  - "English" ("Anglais")
- If you have done at least one new selection, then click on the bottom-right button "Install" or "Modiy", else close the installer window
- Note: the installation of these components can take a long time, depending on your internet connection speed

## Check that VC++ compiler is installed correctly
- Open a Powershell terminal (Type the keys combination "Windows" + "X", then click on "Windows Powershell")
- In the Powershell terminal, in order to enter the Visual C++ build environment, type:
    ```
    cmd.exe /k "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"
    ```
- Then, in order to test the compiler, type:
    ```
    cl
    ```
- This should display something like:
    ```
    Microsoft (R) C/C++ Optimizing Compiler Version 19.24.28316 for x64
    Copyright (C) Microsoft Corporation.  All rights reserved.

    usage: cl [ option... ] filename... [ /link linkoption... ]
    ```
- Then, type:
    ```
    exit
    ```

## Remark

In the following sections, we use the directory "C:\DEVCPP" as the root for most of our work, but you can replace it by any other directory of your choice

## Download all other required software
- Open a Powershell terminal
- In the Powershell terminal, in order to create the directory "C:\DEVCPP\DOWNLOADS", type:
    ```
    New-Item -Path "C:\DEVCPP\DOWNLOADS" -ItemType "Directory" -Force
    ```
- Then, in order to download the Git installer, type:
    ```
    (New-Object System.Net.WebClient).DownloadFile("https://github.com/git-for-windows/git/releases/download/v2.25.1.windows.1/Git-2.25.1-64-bit.exe", "C:\DEVCPP\DOWNLOADS\Git-2.25.1-64-bit.exe")
    ```
- Then, in order to download the CMake installer, type:
    ```
    (New-Object System.Net.WebClient).DownloadFile("https://github.com/Kitware/CMake/releases/download/v3.16.4/cmake-3.16.4-win64-x64.msi", "C:\DEVCPP\DOWNLOADS\cmake-3.16.4-win64-x64.msi")
    ```
- Then, in order to download the vcpkg zipped sources, type:
    ```
    (New-Object System.Net.WebClient).DownloadFile("https://github.com/microsoft/vcpkg/archive/2020.01.zip", "C:\DEVCPP\DOWNLOADS\vcpkg-2020.01.zip")
    ```

## Install Git
- In the Powershell terminal, in order to install Git, type:
    ```
    C:\DEVCPP\DOWNLOADS\Git-2.25.1-64-bit.exe
    ```
- Allow Git to be installed
- Accept all the default options

## Install CMake
- In the Powershell terminal, in order to install CMake, type:
    ```
    C:\DEVCPP\DOWNLOADS\cmake-3.16.4-win64-x64.msi
    ```
- Allow CMake to be installed 
- Accept most of the default options, but *select the option* "Add CMake to the system PATH for the current user"

## Install vcpkg
- In the Powershell terminal, in order to unzip the vcpkg sources in "C:\DEVCPP\PACKAGES\vcpkg-2020.01", type:
    ```
    Expand-Archive -LiteralPath "C:\DEVCPP\DOWNLOADS\vcpkg-2020.01.zip" -DestinationPath "C:\DEVCPP\PACKAGES"
    ```
- Then, once it is finished, in order to build vcpkg.exe, type:
    ```
    C:\DEVCPP\PACKAGES\vcpkg-2020.01\bootstrap-vcpkg.bat
    ```
- Then, once it is finished, in order to make vcpkg.exe executable from everywhere, type:
    ```
    [System.Environment]::SetEnvironmentVariable('Path', $env:Path + ";C:\DEVCPP\PACKAGES\vcpkg-2020.01", [System.EnvironmentVariableTarget]::User)
    ```
- Then, type:
    ```
    [System.Environment]::SetEnvironmentVariable('VCPKG_ROOT', "C:\DEVCPP\PACKAGES\vcpkg-2020.01", [System.EnvironmentVariableTarget]::User)
    ```

## Check that all these required software is installed correctly
- Reboot your computer
- Open a Powershell terminal
- Then, type:
    ```
    git --version
    ```
- This should display:
    ```
    git version 2.25.1.windows.1
    ```
- Then, type:
    ```
    cmake --version
    ```
- This should display:
    ```
    cmake version 3.16.4

    CMake suite maintained and supported by Kitware (kitware.com/cmake).
    ```
- Then, type:
    ```
    vcpkg version
    ```
- This should display:
    ```
    Vcpkg package management program version 2020.01.17-nohash

    See LICENSE.txt for license information.
    ```
- Then, type:
    ```
    $Env:VCPKG_ROOT
    ```
- This should display:
    ```
    C:\DEVCPP\PACKAGES\vcpkg-2020.01
    ```

# Build the project
- Open a Powershell terminal
- In order to clone the project's repository, type:
    ```
    git clone "https://github.com/menuet/cpptuto/" "C:\DEVCPP\PROJECTS\cpptuto"
    ```
- In order to ask vcpkg to download and build the open-source third-parties libraries, type:
    ```
    C:\DEVCPP\PROJECTS\cpptuto\scripts\shell\build-thirdparties.bat
    ```
- This should download and build the open-source third-parties libraries and display something like:
    ```
    "C:\DEVCPP/PACKAGES/vcpkg-2020.01\vcpkg" install --triplet x86-windows catch2 fmt date tl-expected
    Computing installation plan...
    ...
    ...

    ...
    ...
    The package tl-expected:x64-windows provides CMake targets:

        find_package(tl-expected CONFIG REQUIRED)
        target_link_libraries(main PRIVATE tl::expected)
    ```
- Then, once it is done, in order to build the project itself, type:
    ```
    C:\DEVCPP\PROJECTS\cpptuto\scripts\shell\build-project.bat
    ```
- This should display something like:
    ```
    cmake -A x64 -DCMAKE_VERBOSE_MAKEFILE=TRUE "-DCMAKE_TOOLCHAIN_FILE=C:\DEVCPP\PACKAGES\vcpkg-2020.01\vcpkg\scripts\buildsystems\vcpkg.cmake" ..\..\..
    -- Building for: Visual Studio 16 2019
    -- Selecting Windows SDK version 10.0.18362.0 to target Windows 10.0.18363.
    -- The CXX compiler identification is MSVC 19.24.28316.0
    ...
    ...

    ...
    ...
    La génération a réussi.
        0 Avertissement(s)
        0 Erreur(s)

    Temps écoulé 00:00:30.11
    ```
