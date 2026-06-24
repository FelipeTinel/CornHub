#pragma once

#include <iostream>

#include "core/content.hpp"

class ScoreCalculator {

    private:

        Content content;

    public:

        ScoreCalculator(Content content);

        float movieORseries ();
        float viewsORrating ();
        float newORold ();
        float genre_prefered ();

};