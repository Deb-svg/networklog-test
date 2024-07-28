#!/bin/bash

# Test script for networklog

# Function to run a test
run_test() {
    local test_name=$1
    local command=$2
    local expected_output=$3

    echo -n "Running $test_name... "
    output=$($command 2>&1)
    if [[ "$output" == *"$expected_output"* ]]; then
        echo "PASSED"
    else
        echo "FAILED"
        echo "Expected: $expected_output"
        echo "Got: $output"
    fi
}

# Ensure the networklog executable is available
if [[ ! -f ./networklog ]]; then
    echo "Error: networklog executable not found. Please build the project first."
    exit 1
fi

# Running tests
run_test "Help Command" "./networklog help" "NetworkLog - Network Logging Tool"
run_test "Start Logging" "./networklog start" "Network logging started"
run_test "Show Status" "./networklog status" "Network logging is running"
run_test "Stop Logging" "./networklog stop" "Network logging stopped"
run_test "Show Status After Stop" "./networklog status" "Network logging is stopped"
run_test "Check Network" "./networklog check" "PING"
run_test "List Interfaces" "./networklog list-interfaces" "Network interfaces"
run_test "Show Stats" "./networklog stats" "Kernel Interface table"
run_test "Monitor Network" "./networklog monitor" "listening on"
run_test "Generate Report" "./networklog report" "Report generated"
run_test "Archive Logs" "./networklog archive" "Logs archived"

echo "All tests completed."
