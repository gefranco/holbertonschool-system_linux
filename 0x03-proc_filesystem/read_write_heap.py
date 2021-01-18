#!/usr/bin/python3
import re
import sys

if len(sys.argv) < 4:
    print("read_write_heap: Usage: " +
          "read_write_heap.py pid search_string replace_string")
    exit(1)


pid = sys.argv[1]
search_string = sys.argv[2]
replace_string = sys.argv[3]

maps_file = open('/proc/{0}/maps'.format(pid), 'r')
mem_file = open('/proc/{0}/mem'.format(pid), 'rb+', 0)

for line in maps_file.readlines():

    if "[heap]" in line:
        print("Heap found:")
        print(line)
        split_line = line.split()
        adresses = split_line[0].split('-')
        print("Text in [heap]: {0}".format(search_string))

        start = int(adresses[0], 16)
        end = int(adresses[1], 16)
        mem_file.seek(start)
        chunk = mem_file.read(end - start)
        pos = chunk.find(bytes('{0}'.format(search_string), "ASCII"))
        mem_file.seek(start + pos)
        mem_file.write(bytes('{0}'.format(replace_string), "ASCII"))
        print("[heap] changed to: {0}".format(replace_string))

maps_file.close()
# mem_file.close()
