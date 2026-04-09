"""A utility to read and display the contents of a given file."""

import argparse
import sys


def read_file(file_path: str) -> str:
    """Read and return the contents of the specified file.

    Args:
        file_path: Path to the file to read.

    Returns:
        The contents of the file as a string.

    Raises:
        FileNotFoundError: If the file does not exist.
        PermissionError: If the file cannot be read due to permissions.
        IsADirectoryError: If the path is a directory instead of a file.
    """
    with open(file_path, "r", encoding="utf-8") as f:
        return f.read()


def main() -> int:
    """Parse arguments and print file contents."""
    parser = argparse.ArgumentParser(
        description="Read and display the contents of a given file."
    )
    parser.add_argument("file", help="Path to the file to read")
    args = parser.parse_args()

    try:
        contents = read_file(args.file)
        print(contents, end="")
    except FileNotFoundError:
        print(f"Error: File not found: {args.file}", file=sys.stderr)
        return 1
    except PermissionError:
        print(f"Error: Permission denied: {args.file}", file=sys.stderr)
        return 1
    except IsADirectoryError:
        print(f"Error: Path is a directory, not a file: {args.file}", file=sys.stderr)
        return 1

    return 0


if __name__ == "__main__":
    sys.exit(main())
