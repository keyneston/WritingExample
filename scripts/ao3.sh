#!/bin/sh
set -e

pwd

for file in `ls Chapters`; do
  filename="${file%.*}"

  pandoc -o "out/chapter_${filename}.html" "Chapters/${file}" --lua-filter ../scripts/strip_h1.lua
done
