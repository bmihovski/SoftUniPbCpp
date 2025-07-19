
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define MAX_SIZE 64

bool IsWhitePiece(char piece) { return isupper(piece) && piece != '.'; }

bool IsBlackPiece(char piece) { return islower(piece) && piece != '.'; }
void PrintFiguresByColor(const char board[BOARD_SIZE][BOARD_SIZE],
                         bool (*predicate)(char), const char** no_elem_msg) {
  bool has_match = false;
  char current_sym = 0;
  for (size_t row = 0; row < BOARD_SIZE; ++row) {
    for (size_t col = 0; col < BOARD_SIZE; ++col) {
      current_sym = board[row][col];
      if (predicate(current_sym)) {
        has_match = true;
        printf("%c", current_sym);
      }
    }
  }
  printf("\n");
  if (!has_match) {
    printf("%s\n", *no_elem_msg);
  }
}

const char* msg_no_white_fig = "<no white figures>";
const char* msg_no_black_fig = "<no black figures>";
void PrintAllFigures(const char board[BOARD_SIZE][BOARD_SIZE]) {
  PrintFiguresByColor(board, IsWhitePiece, &msg_no_white_fig);
  PrintFiguresByColor(board, IsBlackPiece, &msg_no_black_fig);
}

void ReverseAndPrint(char board[BOARD_SIZE][BOARD_SIZE]) {
  char current_sym = 0;
  for (size_t row = 0; row < BOARD_SIZE; ++row) {
    for (size_t col = 0; col < BOARD_SIZE; ++col) {
      current_sym = board[row][col];
      if (IsWhitePiece(current_sym)) {
        putchar(tolower(current_sym));
      } else if (IsBlackPiece(current_sym)) {
        putchar(toupper(current_sym));
      } else {
        putchar(current_sym);
      }
    }
    putchar('\n');
  }
}

int main() {
  char chess_board[BOARD_SIZE][BOARD_SIZE];
  for (size_t row = 0; row < BOARD_SIZE; ++row) {
    for (size_t col = 0; col < BOARD_SIZE; ++col) {
      scanf(" %c", &chess_board[row][col]);
    }
    getchar();
  }

  PrintAllFigures(chess_board);
  ReverseAndPrint(chess_board);
  return 0;
}
