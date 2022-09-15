#!/bin/sh

find ./keyboards/keebio/sinc/keymaps/andreykaipov/ | entr -cap qmk compile -kb keebio/sinc/rev2 &
find ./keyboards/keebio/iris/keymaps/andreykaipov/ | entr -cap qmk compile -kb keebio/iris/rev3 &
wait
