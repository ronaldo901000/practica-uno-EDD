cmake_minimum_required(VERSION 3.20)
project(UNO)
set(CMAKE_CXX_STANDARD 20)

# Directorios de includes
include_directories(
        UNO/include
        UNO/include/action
        UNO/include/action/robo
        UNO/include/card
        UNO/include/circular-list
        UNO/include/configuracion-partida
        UNO/include/creator-players
        UNO/include/deck
        UNO/include/enum
        UNO/include/generator-stack
        UNO/include/linked-list
        UNO/include/partida
        UNO/include/player
        UNO/include/side
        UNO/include/stack
        UNO/include/uno
)

add_executable(UNO
        UNO/Main.cpp

        # Action
        UNO/src/action/Action.cpp
        UNO/src/action/Color.cpp
        UNO/src/action/Flip.cpp
        UNO/src/action/Numero.cpp
        UNO/src/action/Reverse.cpp
        UNO/src/action/Salto.cpp

        # Action/Robo
        UNO/src/action/robo/Robo.cpp
        UNO/src/action/robo/RoboMasCuatro.cpp
        UNO/src/action/robo/RoboMasDos.cpp
        UNO/src/action/robo/RoboMasDosFlip.cpp
        UNO/src/action/robo/RoboMasSeisFlip.cpp
        UNO/src/action/robo/RoboMasTresFlip.cpp
        UNO/src/action/robo/RoboMasUnoFlip.cpp
        UNO/src/action/robo/RoboMulticolor.cpp

        # Card
        UNO/src/card/Card.cpp

        # Circular List
        UNO/src/circular-list/CircularList.cpp
        UNO/src/circular-list/CircularNode.cpp

        # Configuracion Partida
        UNO/src/configuracion-partida/Configuration.cpp

        # Creator Players
        UNO/src/creator-players/CreatorPlayers.cpp

        # Deck
        UNO/src/deck/Deck.cpp
        UNO/src/deck/GeneratorAction.cpp
        UNO/src/deck/GeneratorCards.cpp
        UNO/src/deck/GeneratorDarkSide.cpp

        # Generator Stack
        UNO/src/generator-stack/GeneratorStack.cpp

        # Linked List
        UNO/src/linked-list/LinkedList.cpp
        UNO/src/linked-list/Node.cpp

        # Partida
        UNO/src/partida/CardComparator.cpp
        UNO/src/partida/CardsManager.cpp
        UNO/src/partida/Partida.cpp

        # Player
        UNO/src/player/Player.cpp
        UNO/src/player/PlayerView.cpp
        UNO/src/player/CardSorter.cpp
        # Side
        UNO/src/side/Side.cpp
        UNO/src/side/SideDark.cpp
        UNO/src/side/SideLight.cpp

        # Stack
        UNO/src/stack/Stack.cpp

        # Uno
        UNO/src/uno/Menu.cpp
        UNO/src/uno/Uno.cpp
)
