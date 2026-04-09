"""Tests for file_reader module."""

import os
import tempfile

import pytest

from file_reader import main, read_file


class TestReadFile:
    """Tests for the read_file function."""

    def test_read_existing_file(self, tmp_path):
        """Test reading an existing file returns its contents."""
        file = tmp_path / "sample.txt"
        file.write_text("Hello, World!", encoding="utf-8")
        assert read_file(str(file)) == "Hello, World!"

    def test_read_multiline_file(self, tmp_path):
        """Test reading a file with multiple lines."""
        file = tmp_path / "multi.txt"
        content = "line1\nline2\nline3\n"
        file.write_text(content, encoding="utf-8")
        assert read_file(str(file)) == content

    def test_read_empty_file(self, tmp_path):
        """Test reading an empty file returns empty string."""
        file = tmp_path / "empty.txt"
        file.write_text("", encoding="utf-8")
        assert read_file(str(file)) == ""

    def test_file_not_found(self):
        """Test that FileNotFoundError is raised for missing file."""
        with pytest.raises(FileNotFoundError):
            read_file("/nonexistent/path/file.txt")

    def test_is_a_directory(self, tmp_path):
        """Test that IsADirectoryError is raised for a directory."""
        with pytest.raises(IsADirectoryError):
            read_file(str(tmp_path))

    def test_read_utf8_content(self, tmp_path):
        """Test reading a file with UTF-8 characters."""
        file = tmp_path / "utf8.txt"
        content = "café résumé naïve"
        file.write_text(content, encoding="utf-8")
        assert read_file(str(file)) == content


class TestMain:
    """Tests for the main CLI function."""

    def test_main_success(self, tmp_path, capsys, monkeypatch):
        """Test main prints file contents and returns 0."""
        file = tmp_path / "test.txt"
        file.write_text("hello", encoding="utf-8")
        monkeypatch.setattr("sys.argv", ["file_reader", str(file)])
        assert main() == 0
        captured = capsys.readouterr()
        assert captured.out == "hello"

    def test_main_file_not_found(self, capsys, monkeypatch):
        """Test main returns 1 for missing file."""
        monkeypatch.setattr("sys.argv", ["file_reader", "/no/such/file.txt"])
        assert main() == 1
        captured = capsys.readouterr()
        assert "File not found" in captured.err

    def test_main_directory(self, tmp_path, capsys, monkeypatch):
        """Test main returns 1 when given a directory."""
        monkeypatch.setattr("sys.argv", ["file_reader", str(tmp_path)])
        assert main() == 1
        captured = capsys.readouterr()
        assert "directory" in captured.err
