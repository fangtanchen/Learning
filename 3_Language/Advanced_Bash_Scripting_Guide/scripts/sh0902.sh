#!/bin/bash

case $1 in
    "hello")
        echo "Hello, how are you?"
        ;;
    "")
        echo "You MUST input parameters, ex>{$0 some word}"
        ;;
    *)
        echo "Usage $0 {hello}"
        ;;
esac
