#!/bin/bash
#
# Get and extract the compiler.
# cd /mnt/c/Users/ckorm/Documents/Ks/uC_Software/Boards/chalandi/Baremetal_v850es_nosdk/Build/tools
# tar -xf gcc-16.2.0-v850-unknown-elf.tar.gz
#
# Add the compiler path.
# cd /mnt/c/Users/ckorm/Documents/Ks/uC_Software/Boards/chalandi/Baremetal_v850es_nosdk/Build
# export PATH="$PATH:/mnt/c/Users/ckorm/Documents/Ks/uC_Software/Boards/chalandi/Baremetal_v850es_nosdk/Build/tools/gcc-16.2.0-v850-unknown-elf/bin"

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

start=$(date +%s)

make --no-print-directory -C "$SCRIPT_DIR" REBUILD_STAGE_1 "$@" &&                \
make --no-print-directory -C "$SCRIPT_DIR" REBUILD_STAGE_2 -k -j $(nproc) "$@" && \
make --no-print-directory -C "$SCRIPT_DIR" REBUILD_STAGE_3 "$@"

end=$(date +%s)
execution_time=$((end - start))

echo "Total execution time: $execution_time seconds"
