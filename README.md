# Test_1

A simple Python utility to read and display the contents of a given file.

## Requirements

- Python 3.7+

## Usage

```bash
python file_reader.py <file_path>
```

### Example

```bash
python file_reader.py README.md
```

## Programmatic Usage

```python
from file_reader import read_file

contents = read_file("path/to/file.txt")
print(contents)
```

## Running Tests

```bash
pip install pytest
pytest test_file_reader.py -v
```