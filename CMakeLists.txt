cmake_minimum_required(VERSION 3.12)
project(Assp2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assp2 main.cpp PremiseChecker/PremiseChecker.cpp PremiseChecker/PremiseChecker.h OrIntroduction/OrIntro.cpp OrIntroduction/OrIntro.h
        ImplicationElimination/ImplicIntro.cpp ImplicationElimination/ImplicIntro.h AndIntroduction/AndIntro.cpp
        AndIntroduction/AndIntro.h AndElimination/AndElimin.cpp AndElimination/AndElimin.h ParseTreeConverter/InfixPostfix/InfixPostfix.cpp
        ParseTreeConverter/InfixPostfix/InfixPostfix.h ParseTreeConverter/PostfixParseTree/PostfixParseTree.h
        ParseTreeConverter/PostfixParseTree/PostfixParseTree.cpp ParseTreeConverter/TreeInfix/TreeInfix.h ParseTreeConverter/TreeInfix/TreeInfix.cpp)