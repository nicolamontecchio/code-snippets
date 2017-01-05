# clojure

## uberjar/main

in `project.clj` add

    :main blablabla.core
    :aot [blablabla.core]

in `src/blablabla/core.clj` add `(:gen-class)` inside the `(ns ...)`

## pmap

from http://www.braveclojure.com/zombie-metaphysics/

    (defn ppmap
      "Partitioned pmap, for grouping map ops together to make parallel
      overhead worthwhile"
      [grain-size f & colls]
      (apply concat
       (apply pmap
              (fn [& pgroups] (doall (apply map f pgroups)))
              (map (partial partition-all grain-size) colls))))
    (time (dorun (ppmap 1000 clojure.string/lower-case orc-name-abbrevs)))
