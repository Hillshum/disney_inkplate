# -----------
# Simple python script to
# create icon header files for Inkplate 6
# Arduino sketches
#
# Takes all files from /icons and saves them to /binary_Icons
#
# -----------

import json
import os, sys

from PIL import Image

if not os.path.isdir("./include/binary_Icons"):
    os.mkdir(os.path.abspath(os.getcwd()) + "/include/binary_Icons")

ICON_SIZE = 64

ids = []

for file in os.listdir("./icons"):
    if file == ".DS_Store":
        continue
    im = Image.open("./icons/" + file)
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

    filename = "icon_" + iconId + ".h"
    with open("./include/binary_Icons/" + filename, "w") as f:
        print("const unsigned char icon_" + file[:-4] + "[] PROGMEM = {", file=f)
        print(",".join(list(map(hex, s))), file=f)
        print("};", file=f)



with open("./include/icons.h", "w") as f:
    f.write("#ifndef ICONS_H\n")
    f.write("#define ICONS_H\n\n")

    for id in ids:
        f.write("#include \"binary_Icons/icon_" + str(id) + ".h\"\n") # include all files

    maxId = max(ids)
    f.write(f"\n\nconst unsigned char *icons[{maxId + 5}];\n")
    f.write("void initIcons()\n")
    f.write("{\n")

    for id in ids:
        f.write("\ticons[" + str(id) + "] = icon_" + str(id) + ";\n")

    f.write("};\n\n") 

    f.write("\n#endif // ICONS_H\n")



# Specify the path to the JSON file
json_file_path = "weather_conditions.json"

# Open the JSON file and load its contents
with open(json_file_path) as json_file:
    conditions = json.load(json_file)

with open("./include/conditions.h", "w") as f:
    f.write("#ifndef CONDITIONS_H\n")
    f.write("#define CONDITIONS_H\n\n")

    f.write("#include \"icons.h\"\n")
    f.write("\n\nstruct Condition {\n")
    f.write("\tString dayName;\n")
    f.write("\tString nightName;\n")
    # f.write("\tint* icon[];\n")
    f.write("\tint iconId;\n")
    f.write("};\n\n")

    f.write(f"Condition* conditions[290];\n")
    f.write("\n\n void initConditions()\n")
    f.write("{\n")
    f.write("\tinitIcons();\n")
    for condition in conditions:
        id = condition["code"] - 1000
        f.write("\tconditions[" + str(id)  + "] = ")
        f.write(f'new Condition();\n')
        f.write(f'\tconditions[{id}]->dayName = "{condition["day"]}";\n')
        f.write(f'\tconditions[{id}]->nightName = "{condition["night"]}";\n')
        # f.write(f'\tstrcpy(conditions[{id}]->dayName, "{condition["day"]}");\n')
        # f.write(f'\tstrcpy(conditions[{id}]->nightName, "{condition["night"]}");\n')
        # f.write(f'\tconditions[{id}]->icon = &icon_{condition["icon"]};\n\n')
        f.write(f'\tconditions[{id}]->iconId = {condition["icon"]};\n\n')

    f.write("}\n\n")


    # f.write(",".join([ "\"" + condition["name"] + "\"" for condition in conditions]))
    f.write("\n\n")

    f.write("\n#endif // CONDITIONS_H\n")



# Do further processing with the parsed JSON data as needed
