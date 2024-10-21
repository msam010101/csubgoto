#!/bin/bash

# Location of csubgoto executable
CSUBGOTO="../build/csubgoto" # Modify this to the actual path of your csubgoto executable

# Number of valid and invalid test cases
NUM_VALID_TESTS=11   # Set the number of valid test cases here
NUM_INVALID_TESTS=1  # Set the number of invalid test cases here

# Color definitions
RED='\033[0;31m'
GREEN='\033[0;32m'
WHITE='\033[0;37m'
NC='\033[0m' # No Color

# Function to print pass/fail messages
function print_result() {
    if [ $1 -eq 0 ]; then
        echo -e "${GREEN}PASS${NC}"
    else
        echo -e "${RED}FAIL${NC}"
        FAILURES=$((FAILURES+1))
    fi
}

# Paths to the examples
VALID_PATH="../examples/valid"
INVALID_PATH="../examples/invalid"

# Total failure counter
FAILURES=0

# Process valid test cases
echo -e "${WHITE}Running valid test cases...${NC}"
for i in $(seq 1 $NUM_VALID_TESTS); do
    FILENAME="valid${i}.cpp"
    echo -e "${WHITE}Processing $VALID_PATH/$FILENAME...${NC}"

    # Compile the original file
    gcc "$VALID_PATH/$FILENAME" -o valid_exec -lstdc++
    if [ $? -ne 0 ]; then
        echo -e "${RED}Compilation failed for $FILENAME${NC}"
        FAILURES=$((FAILURES+1))
        continue
    fi

    # Run the original executable
    ./valid_exec
    if [ $? -ne 0 ]; then
        echo -e "${RED}Execution failed for $FILENAME${NC}"
        FAILURES=$((FAILURES+1))
    else
        echo -e "${GREEN}Original version of $FILENAME passed${NC}"
    fi

    # Run `csubgoto` on the file, converting gotos to switch-case
    $CSUBGOTO --input "$VALID_PATH/$FILENAME" --output "csub_${FILENAME}"
    
    # Compile the modified file
    gcc "csub_${FILENAME}" -o csub_valid_exec -lstdc++
    if [ $? -ne 0 ]; then
        echo -e "${RED}Compilation failed after csubgoto for $FILENAME${NC}"
        FAILURES=$((FAILURES+1))
        continue
    fi

    # Run the modified executable
    ./csub_valid_exec
    if [ $? -ne 0 ]; then
        echo -e "${RED}Execution failed after csubgoto for $FILENAME${NC}"
        FAILURES=$((FAILURES+1))
    else
        echo -e "${GREEN}csubgoto version of $FILENAME passed${NC}"
    fi

    # Cleanup
    rm -f valid_exec csub_valid_exec "csub_${FILENAME}"
done

# Process invalid test cases
echo -e "${WHITE}Running invalid test cases...${NC}"
for i in $(seq 1 $NUM_INVALID_TESTS); do
    FILENAME="invalid${i}.cpp"
    echo -e "${WHITE}Processing $INVALID_PATH/$FILENAME...${NC}"

    # Run `csubgoto` on the invalid file
    $CSUBGOTO --input "$INVALID_PATH/$FILENAME" --output dummy.cpp
    if [ $? -eq 0 ]; then
        echo -e "${RED}csubgoto did not fail for invalid file $FILENAME${NC}"
        FAILURES=$((FAILURES+1))
    else
        echo -e "${GREEN}Invalid test $FILENAME correctly failed${NC}"
    fi

    # Cleanup
    rm -f dummy.cpp
done

# Final summary
echo -e "${WHITE}Total failures: $FAILURES${NC}"

# Exit with -1 if there are any failures
if [ $FAILURES -gt 0 ]; then
    exit -1
else
    exit 0
fi
