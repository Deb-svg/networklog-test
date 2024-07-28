#!/bin/bash

# Function to install dependencies
install_dependencies() {
    echo "Installing dependencies..."
    sudo apt-get update
    sudo apt-get install -y dependency1 dependency2
}

# Function to set up the environment
setup_environment() {
    echo "Setting up the environment..."
    mkdir -p /usr/local/networklog
    cp networklog.sh /usr/local/networklog/
    chmod +x /usr/local/networklog/networklog.sh
}

# Function to create symlinks for easier access
create_symlinks() {
    echo "Creating symlinks..."
    # Creating a symlink in /usr/local/bin for easier access
    ln -sf /usr/local/networklog/networklog.sh /usr/local/bin/networklog
}

# Function to display a message after installation
post_install_message() {
    echo "Installation complete. You can now use 'networklog' command."
}

# Run the main installation steps
main_install() {
    install_dependencies
    setup_environment
    create_symlinks
    post_install_message
}

# Execute the main installation function
main_install

# Run networklog immediately after installation
networklog
