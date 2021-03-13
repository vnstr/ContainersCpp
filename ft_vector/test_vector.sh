#! /bin/zsh

rm user.output
rm std.output

  clang++ -Wall -Wextra -Werror -fsanitize=address ft_vector_test.cpp -o user_bin &&
  ./user_bin > user.output &&
  clang++ -Wall -Wextra -Werror -fsanitize=address std_vector_test.cpp -o bin &&
  ./bin > std.output &&
  diff user.output std.output
