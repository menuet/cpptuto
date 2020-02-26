
SET "PROJECT_ROOT_DIR=%~dp0..\.."

PUSHD "%PROJECT_ROOT_DIR%\out\build\win"

ctest -C Debug -V

POPD
