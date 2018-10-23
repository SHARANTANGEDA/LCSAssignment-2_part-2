//
// Created by sharan on 22/10/18.
//

#include "AndIntro.h"

AndIntro::AndIntro(string s, string r, string param, int sl) {
    statement=s;
    rule=r;
    slash=sl;

    linesused[0]=param[0];
    linesused[1]=param[2];


}

bool AndIntro::check() {
    
}