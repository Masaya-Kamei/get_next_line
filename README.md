# 42 get_next_line

Read one line ending with a newline from a file descriptor.

`int get_next_line(int fd, char **line);`

## Usage example

```zsh
git clone https://github.com/Masaya-Kamei/get_next_line.git;
cd get_next_line;
gcc main/main.c -I. get_next_line.c get_next_line_utils.c;
echo -e "\n---Output---";
./a.out unit_tests/test_files/1_basic.txt;
```

## Tool

- [42TESTERS-GNL](https://github.com/Mazoise/42TESTERS-GNL) (42 gnl tester)
- [Github Actions](https://docs.github.com/ja/actions) (CI/CD tool)
