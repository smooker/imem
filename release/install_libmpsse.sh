#!/bin/bash

echo "Installing libmpsse..."

# Go to build directory
cd build || { echo "Error: build/ directory not found"; exit 1; }

# Find the versioned shared object file (e.g., libmpsse.so.1.0.7)
SOFILE=$(ls libmpsse.so.* 2>/dev/null | grep -Eo 'libmpsse\.so\.[0-9]+\.[0-9]+\.[0-9]+' | head -n 1)

if [ -z "$SOFILE" ]; then
  echo "Error: Could not find versioned shared object (e.g., libmpsse.so.X.Y.Z)"
  exit 1
fi

echo "Found versioned shared object: $SOFILE"

# Full paths
INSTALL_LIB_DIR="/usr/local/lib"
INSTALL_INCLUDE_DIR="/usr/local/include"

# Copy libraries
echo "Copying libraries to $INSTALL_LIB_DIR"
sudo cp "$SOFILE" "$INSTALL_LIB_DIR/"
sudo cp libmpsse.a "$INSTALL_LIB_DIR/"
sudo cp libmpsse.so "$INSTALL_LIB_DIR/"


# Set permissions
echo "Setting permissions on $INSTALL_LIB_DIR/$SOFILE"
sudo chmod 0755 "$INSTALL_LIB_DIR/$SOFILE"

# Create symlink
echo "Creating symlink: libmpsse.so -> $SOFILE"
sudo ln -sf "$INSTALL_LIB_DIR/$SOFILE" "$INSTALL_LIB_DIR/libmpsse.so"

# Copy headers
echo "Copying header files to $INSTALL_INCLUDE_DIR"
cd ..
sudo cp include/*.h "$INSTALL_INCLUDE_DIR"
sudo cp libftd2xx/*.h "$INSTALL_INCLUDE_DIR"

# Update shared library cache
echo "Running ldconfig..."
sudo ldconfig

echo "✅ libmpsse installation completed successfully!"
