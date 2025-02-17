#!/bin/bash

set -e

FRAMEWORKS_DIR="Frameworks"
OUTPUT_DIR="ZippedFrameworks"

mkdir -p "$OUTPUT_DIR"

# Function to zip and compute checksum
zip_and_checksum() {
    local framework_name=$1
    local zip_path="$OUTPUT_DIR/${framework_name}.xcframework.zip"

    echo "Zipping $framework_name..."
    zip -r "$zip_path" "$FRAMEWORKS_DIR/${framework_name}.xcframework"

    echo "Computing checksum for $framework_name..."
    checksum=$(swift package compute-checksum "$zip_path")

    echo "$framework_name checksum: $checksum"
    echo "$framework_name: $checksum" >> "$OUTPUT_DIR/checksums.txt"
}

# Zip and compute checksum for each framework
zip_and_checksum "Autobooks"
zip_and_checksum "Autobooks-FiservOnly"
zip_and_checksum "triPOSMobileSDK"

echo "All frameworks zipped and checksums computed. See $OUTPUT_DIR/checksums.txt for results."
