/*
 * main.cpp
 *
 *  Created on: May 6, 2019
 *      Author: kqalea
 */

#define CATCH_CONFIG_RUNNER

#include"topic.hpp"
#include"../test/catch.hpp"


int main(int argc, char* argv[]){

    int result = Catch::Session().run(argc, argv);
    return result;
}
