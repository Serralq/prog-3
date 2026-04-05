#!/usr/bin/env bash
set -euo pipefail

curl --proto '=https' --tlsv1.2 -sSf -L https://install.determinate.systems/nix | sh -s -- install --no-confirm
. /nix/var/nix/profiles/default/etc/profile.d/nix-daemon.sh
nix-shell --pure --run "./test.sh"
