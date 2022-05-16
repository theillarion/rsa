#!/bin/bash

count_arguments=1

GREEN="\033[92m"
RED="\033[91m"
END="\033[0m"

if [[ $# -eq $count_arguments ]]; then
  argument=$(echo $1 | tr "[:upper:]" "[:lower:]")
  if [[ "$argument" == "debug" ]] || [[ "$argument" == "release" ]]; then
    if cmake -DCMAKE_BUILD_TYPE="$argument" .; then
      echo -e "${GREEN}Build complete${END}"
    else
      echo -e "${RED}Error build${END}"
    fi
  else
    echo -e "${RED}Wrong argument${END}"
  fi
else
  echo -e "${RED}Wrong number of arguments${END}"
fi