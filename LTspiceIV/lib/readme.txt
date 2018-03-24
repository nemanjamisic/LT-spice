Drop Down Menus for selecting your tube

LT Spice can be made to provide a nice drop down box to select your tubes. In addition, once you set this up, you don't need to add the .INC files to your spice program; it is automatically set up when you grap the tube symbol.

To do this requires only a couple steps:
1. Open the .ASY symbol file associated with the part. For example TRIODE.ASY that is in the LT spice folder under SWCADIII\lib\sym\misc folder. (you can do this from within LTSpice by choosing open>files of all types in that directory).
2. Edit three attributes:
2a. Spice Model = Triode (or whatever at least one subcircuit is named in your normally used .inc file)
2b. ModelFile = name of your include file (for example, dmtriodep.inc)
2c. Remove the Value field (I had to do this with a text editor)
3. Copy the model file (for example dmtriodep.inc) to the SWCADIII\lib\sub folder

Now, you don't need a .inc file in your spice program, and you get a nice pull down menu to boot.

To make this even easier, I have attached 7 files to this post.
1. triode_dd_htr.asy. Copy this into the ...\lib\sym\misc folder
2. triode_dd.asy. Ditto
3. tetrode_dd.asy. Ditto.
When you make a schematic, you can pick one of these for the tubes in the miscellaneous folder of parts.

4. triode.txt Copy this into the ...\lib\sub folder.
triode.txt has triode models for devices that also model the heaters. This is currently 6SN7, 12AT7, 12AU7, 12AX7.
5. triode_nh.txt. ditto
triode_nh.txt has models for over 40 triodes.
6. tetrode.txt. ditto
Note that these are couped into the subcircuit folder, not the symbol folder.

7. t_curves.asc. An example spice file that displays curves for tubes in each of these files.
Copy this into whatever directory you put your spice files into.

Enjoy,

Steve
