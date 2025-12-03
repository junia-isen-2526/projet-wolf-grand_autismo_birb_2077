autocmd BufWritePost *.{c,h} !clang-format -i % 2> /dev/null
