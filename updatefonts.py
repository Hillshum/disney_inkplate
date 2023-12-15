# iterate over all fonts in the fonts directory

import os
import pathlib

directory = pathlib.Path("include/Fonts")
file_list = os.listdir(directory)

for file in file_list:
    with open(directory / file, "r+", encoding="utf8") as f:
        new_name = file.upper().replace(".", "_")
        file_contents = f.read()
        f.seek(0)
        f.write(f"#ifndef {new_name}\n")
        f.write(f"#define {new_name}\n\n")
        f.write(file_contents)
        f.write(f"\n#endif // {new_name}\n")
