# -----------
# Simple python script to
# create icon header files for Inkplate 6
# Arduino sketches
#
# Takes all files from /icons and saves them to /binary_Icons
#
# -----------

import json
import os
import pathlib

from PIL import Image

ROOT_FOLDER_NAME = 'binary_icons'
ROOT_DESTINATION = pathlib.Path("./include", ROOT_FOLDER_NAME)

if not os.path.isdir(ROOT_DESTINATION):
    os.mkdir(os.path.abspath(os.getcwd()) / ROOT_DESTINATION)

ICON_SIZE = 64


def process_folder(fname):
    # fname = pathlib.Path(fname)
    ids = []
    if not os.path.isdir(ROOT_DESTINATION / fname):
        os.mkdir(os.path.abspath(os.getcwd()) / ROOT_DESTINATION / fname)
    for file in os.listdir(pathlib.Path("./icons") / fname):
        print(file)
        if file == ".DS_Store":
            continue
        im = Image.open(pathlib.Path("./icons") / fname / file)
        iconId = file[:-4]
        ids.append(int(iconId))
        im = im.resize((ICON_SIZE, ICON_SIZE))
        alp = im.split()[-1]
        s = [0 for x in range(ICON_SIZE * ICON_SIZE)]
        for y in range(ICON_SIZE):
            for x in range(ICON_SIZE):
                # print((x,y), im.getpixel((x, y)))
                if alp.getpixel((x, y)) > 128:
                    s[(x + ICON_SIZE * y) // 8] |= 1 << (7 - (x + ICON_SIZE * y) % 8)

        filename = f"icon_{fname}_{iconId}.h"
        with open(ROOT_DESTINATION / fname / filename, "w") as f:
            print(f"const unsigned char icon_{fname}_{file[:-4]}[] PROGMEM = {'{'}", file=f)
            print(",".join(list(map(hex, s))), file=f)
            print("};", file=f)



    with open(ROOT_DESTINATION / fname / f"{fname}_icons.h", "w") as f:
        f.write(f"#ifndef {fname.upper()}_ICONS_H\n")
        f.write(f"#define {fname.upper()}_ICONS_H\n\n")

        for id in ids:
            f.write(f"#include \"{ROOT_FOLDER_NAME}/{fname}/icon_{fname}_{str(id)}.h\"\n") # include all files

        maxId = max(ids)
        f.write(f"\n\nconst unsigned char *{fname}_icons[{maxId + 5}];\n")
        f.write(f"void init{str(fname).capitalize()}Icons()\n")
        f.write("{\n")

        for id in ids:
            f.write(f'\t{fname}_icons[{str(id)}] = icon_{fname}_{str(id)};\n')

        f.write("};\n\n") 

        f.write(f"\n#endif // {fname.upper()}_ICONS_H\n")

ICON_FOLDERS = ['day', 'night']

for folder in ICON_FOLDERS:
    process_folder(folder)

# Specify the path to the JSON file
json_file_path = "weather_conditions.json"

# Open the JSON file and load its contents
with open(json_file_path) as json_file:
    conditions = json.load(json_file)

with open("./include/conditions.h", "w") as f:
    f.write("#ifndef CONDITIONS_H\n")
    f.write("#define CONDITIONS_H\n\n")

    for folder in ICON_FOLDERS:
        f.write(f"#include \"binary_icons/{folder}/{folder}_icons.h\"\n")
    # f.write("#include \"icons.h\"\n")
    f.write("\n\nstruct Condition {\n")
    f.write("\tString dayName;\n")
    f.write("\tString nightName;\n")
    # f.write("\tint* icon[];\n")
    f.write("\tint iconId;\n")
    f.write("};\n\n")

    f.write(f"Condition* conditions[290];\n")
    f.write("\n\n void initConditions()\n")
    f.write("{\n")
    # f.write("\tinitIcons();\n")
    for folder in ICON_FOLDERS:
        f.write(f"\tinit{folder.capitalize()}Icons();\n")
    for condition in conditions:
        id = condition["code"] - 1000
        f.write("\tconditions[" + str(id)  + "] = ")
        f.write(f'new Condition();\n')
        # f.write(f'\tconditions[{id}]->dayName = "{condition["day"]}";\n')
        # f.write(f'\tconditions[{id}]->nightName = "{condition["night"]}";\n')
        f.write(f'\tconditions[{id}]->iconId = {condition["icon"]};\n\n')

    f.write("}\n\n")


    # f.write(",".join([ "\"" + condition["name"] + "\"" for condition in conditions]))
    f.write("\n\n")

    f.write("\n#endif // CONDITIONS_H\n")



# Do further processing with the parsed JSON data as needed
