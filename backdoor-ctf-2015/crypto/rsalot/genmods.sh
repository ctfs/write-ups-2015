#!/bin/bash
for i in pems/*.pem; do MOD="`openssl rsa -pubin -inform PEM -noout -modulus < $i`"; echo "${MOD:8}" > "mods/$(basename $i).mod"; done
