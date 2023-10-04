cmake_minimum_required(VERSION 3.26)
project(c_pic_proc_ym1721 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(sod_118)

add_executable(c_pic_proc_ym1721
        sod_118/sod.c
        sod_118/sod.h
        sod_118/sod_img_reader.h
        sod_118/sod_img_writer.h
        Main.c
        PicProcess.c
        PicProcess.h
        Picture.c
        Picture.h
        Utils.c
        Utils.h)
