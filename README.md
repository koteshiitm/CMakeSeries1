# CMakeSeries1
Cross platform for C++ development with CMake

# Build commands
If you are under build folder and CMakeLists.txt is outside of build folder, then

cmake ..

cmake --build .

cmake -S . -B build  <== -S refers source directory; . refers current directory;  -B refers Build directory;  build refers build directory path
         Here by default it will take Visual studio generator and do the setup.
         
cmake --build build  <== creates executable path under build directory.

# git commands
git add .

git commit -m "Your comment"

git push
