cmake_minimum_required (VERSION 2.8)

set(SRC_FILES
	main.cpp
	DefaultBoard.cpp
	GameState.cpp
   )

add_executable(TicTacToe ${SRC_FILES})
