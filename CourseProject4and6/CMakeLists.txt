cmake_minimum_required(VERSION 3.20)
project(CourseProject4and6)



set(SOURCES
        main.cpp
        abstractClass/WorkerOfCompany.cpp
        realizationOfClass/Administrator.cpp
        realizationOfClass/Manager.cpp
        realizationOfClass/Programer.cpp
        )
set(HEADERS
        interface/ICompany.h
        interface/IEmployee.h
        abstractClass/WorkerOfCompany.h
        realizationOfClass/Administrator.h
        realizationOfClass/Manager.h
        realizationOfClass/Programer.h
        )

add_executable(CourseProject4and6 ${HEADERS} ${SOURCES})


set_target_properties(
        CourseProject4and6 PROPERTIES
        CXX_STANDARD 17 # требуемый стандарт с++
        CXX_STANDARD_REQUIRED ON # если нет компилятора 17 выводиться ошибка
)