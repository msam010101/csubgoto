# NOTICE

THIS PROJECT IS NOWHERE NEAR COMPLETE. ITS BEING WORKED ON. AT THE MOMENT THERES LIKELY NOTHING USEFUL HERE. THESE ARE NOT THE REPOSITORIES YOU ARE LOOKING FOR!

# csubgoto

This utility transforms C/C++ code by replacing `goto` statements with equivalent state machine logic using a `switch-case` construct. It can be used as a C/C++ precompiler to transform code before compilation with WebAssembly.

## Features

- Parses valid C/C++ code.
- Identifies functions containing `goto` statements.
- Converts `goto` statements to state machine logic.
- Supports command line input/output file names and pipes.
- Ensures the transformed code functions identically to the original.

## Requirements

- CMake >= 3.5
- LLVM and Clang libraries installed on your system.

## Building

1. **Install LLVM and Clang**

   Ensure that LLVM and Clang are installed and properly configured. You can download them from the official [LLVM website](https://llvm.org/).

2. **Clone the Repository**

   ```bash
   git clone https://github.com/jdbrinton/csubgoto.git
   cd csubgoto

## Prompts

### Prompt 1

Modern WebAssembly and WASM compilers do not support the `goto` directive. So it is not possible to compile code that uses `goto` directives directly to WASM. In C or C++, write a C/C++ preprocessor utility called csubgoto that parses C/C++ code for all `goto` logic and transforms the `goto` logic into state machine logic. Smartly handle all cases, including labels and `goto` statements jumping in or out of plain code blocks, `switch`, `for`, `while`, and `do` blocks. Have the smallest possible scope for each state machine. The preprocessor shall input valid C++14 code, and output the modified code without `goto` statements. Except for code replacements and code substitutions, the output code shall look identical to the input code. The input and/or output file names shall be passable via commandline arguments. And the application shall also support both input and output pipes.

Procedure:
1. Use libclang to parse C++14 compliant code into an abstract syntax tree (AST).
2. Traverse the AST and identify each function with one or more `goto` statements.
3. Validate that they only jump to labels within the same function.
4. In each function, for each `goto` statement, find the smallest code block (whether its the function scope, a plain code block, a `for` code block, `switch` code block, `while` code block, or `do` code block) that contains the `goto` statement and its label. If there are other `goto` statements inside of that code block, expand the scope to the smallest code block that contains all of them and their labels. Do this recursively and, for each state machine, create a data structure.
5. For each state machine, insert the csubgoto initializing code at the beginning of the block (ex. `enum { __STATE_CSUBGOTO_START__, label1, label2, __STATE_CSUBGOTO_FOR1_START__, __STATE_CSUBGOTO_FOR1_END__ } __csubgoto_state__ = __STATE_CSUBGOTO_START__; switch(__csubgoto_state__) { case __STATE_CSUBGOTO_START__:`).
6. Replace any `goto` with a state set and break (ex. `{__csubgoto_state__ = label1; break;}`)
7. Replace any labels with a case statement (ex. `case label1:`)
8. If a `goto` or label is inside of a `for` statement, roll the for loop functionality into the state machine and replace any `for` statement with a code snippet (see example). Be sure to also replace the `for` block closing bracket with a code snippet (see example).
9. Replace any `switch` statement with a code snippet (infer how this should work). Be sure to also replace the `switch` block closing bracket with a code snippet. Be sure to add any case.
10. Replace any `while` statement with a code snippet (infer how this should work). Be sure to also replace the `while` block closing bracket with a code snippet.
11. Replace any `do` statement with a code snippet (infer how this should work). Be sure to also replace the `do` block closing bracket with a code snippet.
12. If there are any variable scopes that are affected by the removal of `for`, `switch`, `while`, or `do` blocks, add the necessary logic to maintain the original functionality.
12. Write the modified contents out to a file.


Example input:
```
void example1(int n) {
    int i = 0;

    for (i = 0; i < n; i++) {
        if (i == 3) {
            goto label1;
        }
    }

    printf("After loop\n");
    return;

label1:
    printf("Jumped to label1\n");
}
```

Example output:
```
void example1(int n) {


/******************************************
 *
 * csubgoto - CODE INSERTION START
 *
 *****************************************/
enum { __STATE_CSUBGOTO_START__, label1, __STATE_CSUBGOTO_FOR1_START__, __STATE_CSUBGOTO_FOR1_END__ } __csubgoto_state__ = __STATE_CSUBGOTO_START__; switch(__csubgoto_state__) { case __STATE_CSUBGOTO_START__:
/******************************************
 *
 * csubgoto - CODE INSERTION STOP
 *
 *****************************************/


    int i = 0;



/******************************************
 *
 * csubgoto - CODE REPLACEMENT START
 *
 *****************************************/
i = 0;
case __STATE_CSUBGOTO_FOR1_START__:
if(!( i < n)) {__csubgoto_state__ = __STATE_CSUBGOTO_FOR1_END__; break;}
/******************************************
 *
 * csubgoto - CODE REPLACEMENT STOP
 *
 *****************************************/


        if (i == 3) {


/******************************************
 *
 * csubgoto - CODE REPLACEMENT START
 *
 *****************************************/
{__csubgoto_state__ = label1; break;}
/******************************************
 *
 * csubgoto - CODE REPLACEMENT STOP
 *
 *****************************************/


        }


/******************************************
 *
 * csubgoto - CODE REPLACEMENT START
 *
 *****************************************/
i++;
{__csubgoto_state__ = __STATE_CSUBGOTO_FOR1_START__; break;}
case __STATE_CSUBGOTO_FOR1_END__:
/******************************************
 *
 * csubgoto - CODE REPLACEMENT STOP
 *
 *****************************************/


    printf("After loop\n");
    return;



/******************************************
 *
 * csubgoto - CODE REPLACEMENT START
 *
 *****************************************/
case label1:
/******************************************
 *
 * csubgoto - CODE REPLACEMENT STOP
 *
 *****************************************/


    printf("Jumped to label1\n");
}
```

For now just provide solid robust code scaffolding so other agents can develop each section rather independently as stand alone functions.

### Prompt 2

The following is my instructions for developing the code:

```

```

I don't want you to develop the code. I want you to give me some examples of complex code and how it should be parsed so I can pass that to the agent doing the coding.

### Prompt 3

Provide complete code. Do Not provide TODO sections or unimplemented features. I'm relying on you to do the work.


