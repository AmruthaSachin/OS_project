#!/bin/bash

# Function to compile and run C files in the background
compile_and_run() {
    local file=$1
    local output=${file%.*}   # Strip the file extension for output file name

    # Compile the C program
    gcc -o "$output" "$file" 2>/dev/null

    # Check if compilation was successful
    if [[ $? -ne 0 ]]; then
        echo "Compilation error in $file"
    else
        echo "Running $file..."
        # Run the executable in the background, directing its output to a separate terminal
        gnome-terminal -- bash -c "./$output; exec bash"
    fi
}

# Check if at least one argument is provided
if [[ $# -lt 1 ]]; then
    echo "Usage: $0 {sjf|rr|fcfs|srtf} [...]"
    exit 1
fi

# Loop through all provided arguments
for arg in "$@"; do
    case $arg in
        sjf)
            compile_and_run "sjf.c" &
            ;;
        rr)
            compile_and_run "rr.c" &
            ;;
        fcfs)
            compile_and_run "fcfs.c" &
            ;;
        srtf)
            compile_and_run "srtf.c" &
            ;;
        *)
            echo "Invalid argument: $arg. Please use 'sjf', 'rr', 'fcfs', or 'srtf'."
            ;;
    esac
done

# Wait for all background processes to finish
wait

