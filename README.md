# File-Based Array and String Processing in C

File-Based Array and String Processing in C is a collection of thirteen independent console exercises focused on transforming structured text-file data into bounded arrays, analyzing numeric and textual values, presenting selected results, and saving derived data to new files. The work progresses from arithmetic operations on integer and real-number records to conditional selection, aggregation, index-based processing, string-length evaluation, character classification, and mixed string-number records. It demonstrates a systematic approach to input processing, array manipulation, interactive filtering, and persistent output in C.

## Overview

Each exercise follows a complete data-processing workflow:

1. Read structured records from a text file selected at runtime.
2. Build an array by applying an exercise-specific transformation or selection rule.
3. Display the resulting array or a requested subset of its elements.
4. Calculate an aggregate result such as a sum, average, minimum, maximum, or frequency.
5. Write the values that satisfy the final condition to `Uscita.txt`.

The exercises are self-contained. Every `Exercise NN` directory contains one C source file and one `file.txt` sample dataset. Arrays hold at most ten values in most exercises, while Exercise 02 uses a capacity of seven values. Records that exceed the available capacity are not loaded.

## Exercise Guide

| Exercise | Input records | Processing objective |
| --- | --- | --- |
| 01 | Two integers per line | Store pair sums, display values from a selected position, find the greatest positive value, and export non-positive values. |
| 02 | Two real numbers per line | Store the greater value from each pair, filter values within a user-defined interval, calculate the square of the total, and export values below the derived limit. |
| 03 | Two integers per line | Store positive pair sums, identify multiples of five, calculate the average of odd values, and export values greater than ten. |
| 04 | Two integers per line | Store the greater value from each pair, display positive values, calculate the overall average, and export multiples of five. |
| 05 | Three real numbers per line | Store row totals, filter them by a user-defined threshold, sum positive values, and export elements at even positions. |
| 06 | One integer and one real number per line | Select real values paired with even integers, display elements at odd positions, calculate the positive-value average, and export values below that average. |
| 07 | Two integers per line | Select second values that divide the corresponding first values, display elements at odd positions, average odd values, and export values below that average. |
| 08 | One integer and one string per line | Select integers smaller than the length of their associated strings, display elements at even positions, process squared even values, and export divisors of the calculated result. |
| 09 | One string and one real number per line | Select values associated with strings longer than five characters, display negative values, locate the minimum, and export positive values. |
| 10 | Two integers per line | Store valid pair ratios, filter them by a user-defined threshold, normalize unit values to zero, and export non-zero results. |
| 11 | One integer and one real number per line | Select real values paired with odd integers, display elements at odd positions, calculate separate positive and negative totals, and export threshold-matching values. |
| 12 | One alphanumeric string and one positive integer per line | Convert the indicated character into a vowel classification value, count zero values, average non-zero values, and export classifications from two through four. |
| 13 | One string and two integers per line | Classify string lengths against minimum and maximum bounds, count consecutive negative-one and zero patterns, find the maximum, and export squares of non-zero values. |

Array positions are zero-based wherever an exercise asks for or reports an index.

## Requirements

To build and run the exercises, use:

- A C compiler such as GCC or Clang.
- A terminal capable of changing directories and starting console programs.
- The standard C library, including string support where required.

No external libraries, package managers, or build systems are required.

## Build and Run

Run each program from its own exercise directory. This ensures that the included `file.txt` can be entered directly at the filename prompt and that the generated `Uscita.txt` remains associated with the correct exercise.

### Windows

From PowerShell, open the repository root and compile a single exercise as follows:

```powershell
Set-Location "Exercise 01"
gcc exercise_01.c -o exercise_01.exe
```

Run it with:

```powershell
.\exercise_01.exe
```

When prompted for the input filename, enter:

```text
file.txt
```

After the program finishes, inspect its generated data with:

```powershell
Get-Content .\Uscita.txt
```

Return to the repository root before selecting another exercise:

```powershell
Set-Location ..
```

To compile all thirteen exercises from the repository root:

```powershell
1..13 | ForEach-Object {
    $id = $_.ToString("00")
    Push-Location "Exercise $id"
    gcc "exercise_$id.c" -o "exercise_$id.exe"
    Pop-Location
}
```

To run all compiled exercises sequentially from the repository root:

```powershell
1..13 | ForEach-Object {
    $id = $_.ToString("00")
    Push-Location "Exercise $id"
    & ".\exercise_$id.exe"
    Pop-Location
}
```

### macOS and Linux

From a terminal, open the repository root and compile a single exercise as follows:

```sh
cd "Exercise 01"
cc exercise_01.c -o exercise_01
```

Run it with:

```sh
./exercise_01
```

When prompted for the input filename, enter:

```text
file.txt
```

After the program finishes, inspect its generated data with:

```sh
cat Uscita.txt
```

Return to the repository root before selecting another exercise:

```sh
cd ..
```

To compile all thirteen exercises from the repository root with a POSIX-compatible shell:

```sh
n=1
while [ "$n" -le 13 ]; do
    id=$(printf "%02d" "$n")
    (cd "Exercise $id" && cc "exercise_$id.c" -o "exercise_$id")
    n=$((n + 1))
done
```

To run all compiled exercises sequentially from the repository root:

```sh
n=1
while [ "$n" -le 13 ]; do
    id=$(printf "%02d" "$n")
    (cd "Exercise $id" && "./exercise_$id")
    n=$((n + 1))
done
```

The `cc` command normally invokes the system C compiler. Replace it with `gcc` or `clang` if that compiler is installed under its explicit name.

## Interactive Input

All programs first request the name of an input file. The supplied dataset is named `file.txt` in every exercise directory. Some exercises then request an additional value:

| Exercise | Additional input |
| --- | --- |
| 01 | A valid starting array position. |
| 02 | The lower bound used to define the filtering interval. |
| 05 | A threshold used to select row totals. |
| 10 | A threshold used to select ratios. |
| 11 | A threshold used for the final value selection. |

Exercises not listed in this table require only the input filename.

## Input and Output Behavior

Input files are whitespace-delimited. Spaces, tabs, and line breaks separate values, while each logical row must follow the record format shown in the exercise guide. Strings are single tokens and therefore must not contain spaces.

During execution, each program prints the array derived from the input and the results of its requested analysis. The final selection is written to `Uscita.txt` in the current working directory. Running the same exercise again replaces that file with the new result, so copy any output that must be retained before another run.

The bundled `file.txt` files provide ready-to-use datasets. They may be replaced or supplemented with custom text files that preserve the corresponding exercise's record format and value types.

## Concepts Demonstrated

- Sequential text-file reading and formatted record parsing.
- Fixed-capacity arrays with an effective element count.
- Conditional loading and transformation of numeric data.
- Integer and floating-point arithmetic.
- Position-based and value-based array traversal.
- Aggregations including sums, averages, extrema, and occurrence counts.
- String-length comparisons and character classification.
- Interactive thresholds and range selection.
- Creation of derived text-file output.
