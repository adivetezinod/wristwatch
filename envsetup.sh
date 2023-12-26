#!/bin/sh

lunch() {
    NAME=$1
    cp config/$NAME/board_hal.cpp src/board_hal.cpp
    cp config/$NAME/board_config.h include/board_config.h
}