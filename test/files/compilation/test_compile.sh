#!/usr/bin/bash
# set -x

# Needs to be executed from Master module not in independent submodule
function check_master() {
  printf "Here 1"
  if ! (git submodule status | grep -q ".*nand2tetris.*"); then
    printf "\nBe sure you are in master repository\n"
    exit 1
  fi
}

function set_jack_files() {

  mapfile -t jack_files < <(find -L "${current_path}" -type f -name "*.jack" -and -path "*10*")

}

#For each jack and xml will be generated
#prefix=this->submodule/test/compilation
#xml location == prefix+xxx.jack

function set_compiler_xml_output() {

  local prefix="${compiler_path}/test/compilation"
  local suffix="xml"
  for file in "${jack_files[@]}"; do
    name_no_extension=$(sed -E -e 's/.*(\/.*\/.*\.).*/\1/g' \
      -e 's/(.*)\/(.*\..*)/\1\_\2/g' <<<"${file}")
    generated_output="${prefix}${name_no_extension}${suffix}"
    printf "\n%s\n" "${generated_output}"
    "${compiler_path}/build/jack_compiler" "${file}" "${generated_output}"
    compiler_xml_output+=("${generated_output}")
    # nvim -d "$(awk 'BEGIN{FS="."}{print $1}' <<<"${file}").xml" "${generated_output}"
  done
}

function check_compiler_binarie() {
  if [[ ! -x "${compiler_path}/build/jack_compiler" ]]; then
    printf "\nBe sure the binarie was generated run the make command in  %s \n" "${compiler_path} "
    exit 1
  fi
}
function compare_files() {
  for index in "${!jack_files[@]}"; do
    jack_to_xml=$(awk 'BEGIN{FS="."}{print $1}' <<<"${jack_files[${index}]}")
    # printf "%s" "${jack_to_xml}.xml"
    nvim -d "${compiler_xml_output[${index}]}" "${jack_to_xml}.xml"
  done

}
function main() {

  check_master
  local current_path
  current_path="$(git rev-parse --show-toplevel)"
  local compiler_path
  compiler_path="${current_path}/$(awk '/[C|c]ompiler/{print $2}' <(git submodule status))"

  local jack_files
  set_jack_files

  check_compiler_binarie
  local compiler_xml_output
  compiler_xml_output=()
  set_compiler_xml_output
  compare_files

  # local counter=0
  # for file in "${jack_files[@]}"; do
  #   ((counter++))
  #   printf "%d" "${counter}"
  #   printf "%s" "${file}"
  # done

}
main "$@"
