# clojure

## uberjar/main

in `project.clj` add

    :main blablabla.core
    :aot [blablabla.core]

in `src/blablabla/core.clj` add `(:gen-class)` inside the `(ns ...)`
