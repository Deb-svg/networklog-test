# NetworkLog

NetworkLog is a network logging tool designed to help monitor and log network activities. It includes various commands to start and stop logging, check network status, list interfaces, and more.

## Features

- Start and stop network logging
- Display current logging status
- Check network connectivity
- List network interfaces
- Show network statistics
- Monitor network activity
- Generate network reports
- Archive logs

## Installation

### Using the Install Script

To install NetworkLog using the provided install script, run:

```sh
./scripts/install.sh
```

## Manual Installation

1. Clone the Repository

   ```sh
   git clone https://github.com/Deb-svg/networklog-test.git
   cd networklog-test
   ```
   
2. Build the Project

   ```sh
   make
   ```
3. Install the Executable

   ```sh
   sudo make install
   ```
   
4. Install Additional Scripts

   ```sh
   sudo make install-scripts
   ```
   
5. Install Everything

   ```sh
   sudo make install-all
   ```
   
## Usage

After installing NetworkLog, you can use the following commands:

   ```sh
   networklog help               # Show help message
   networklog start              # Start network logging
   networklog stop               # Stop network logging
   networklog status             # Show logging status
   networklog log                # Display current log
   networklog check              # Check network status
   networklog list-interfaces    # List network interfaces
   networklog stats              # Show network statistics
   networklog monitor            # Monitor network activity
   networklog report             # Generate network report
   networklog archive            # Archive logs
   ```

### Example

To start logging:

   ```sh
   networklog start
   ```

To stop logging:

   ```sh
   networklog stop
   ```

To display the current log:

   ```sh
   networklog log
   ```

## Testing

To run the tests for NetworkLog:

1. Build the Project

   ```sh
   make
   ```
   
2. Run the Test Script

   ```sh
   make test
   ```
   
This will execute the `test_networklog.sh` script and display the results of the tests.

## Contributing

We welcome contributions! Please follow these steps to contribute:

1. Fork the repository on GitHub.
2. Create a new branch from `main`.
3. Make your changes.
4. Commit your changes with clear commit messages.
5. Push your changes to your fork.
6. Open a pull request to the `main` branch of the original repository.

For detailed guidelines,  press [CONTRIBUTING](c.md).

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
