cmake_minimum_required(VERSION 3.13)

#
#   Project Security.Dionysus
#
#       -SubProject [00] - Holocene-DryasEvent
#       -SubProject [01] - The Annunciation (The reason why this year is 2023)
#       -SubProject [02] - Lemegeton The Lesser Key of Solomon(Clavicula Salomonis)
#
#   When listening Bossa Nova Jazz, and drinking in the cafe.
#   The New Holy Orders are waiting for us.
#   We created the world, and enjoy it.
#
#   @author 2023/07/17 tonoshiki piyoma
#

project(Project.Dionysus VERSION 1.0.1 LANGUAGES CXX)

add_subdirectory(${PROJECT_SOURCE_DIR}/Agent.Horaisan)
add_subdirectory(${PROJECT_SOURCE_DIR}/Plugin.Example)
add_subdirectory(${PROJECT_SOURCE_DIR}/Plugin.RPC)