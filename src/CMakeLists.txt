cmake_minimum_required (VERSION 2.8)

set(SRC_FILES
	DefaultBoard.cpp
	Game.cpp
	GameFlow.cpp
	TraditionalGame.cpp
   )

add_executable(TicTacToeTest "main.cpp" ${SRC_FILES})
add_library(TicTacToe SHARED ${SRC_FILES})
