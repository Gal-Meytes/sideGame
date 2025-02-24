# Exit on error
set -e

# Define build directory
BUILD_DIR="build"

# Create and navigate to the build directory
mkdir -p $BUILD_DIR
cd $BUILD_DIR

# Run CMake to configure the project
cmake ..

# Compile the project
make -j$(nproc)

# Navigate back
cd ..
