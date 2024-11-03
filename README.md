Hello, I'm using QTMaker and I plan to make an inventory system.
Unfortunately, it's crashing.

The features should be like this:

Two dropbox:
- Category Dropbox
- Item Dropbox (10 items that update depending on the category selected)

  Add button - When clicked, there will be a prompt for the user to specify how many will be added, then, it will be saved in a txt file.
  Load button - When clicked, it will show in a table in this format Category, Item, Quantity, Timestamp (Time and Date), ID, Description, Checkbox

There will be 5 categories with 10 items
Appliances (ID 1111) - Aircon Electric Fan Water Dispenser Television Computer Princer Projector Sound System Flourescent Light Laptop
Sports Equipment (ID 2222) - Basketball Tennis Ball Shuttlecock Volleyball, Court Ring, Net, Pole, Gym Mat, Tennis Table, Court Board
Lab Equipment (ID 3333) - Microscope, Test Tube, Beaker, Thermometer, Bunsen Burner, Safety Goggle, Funnel, Incubator, Calorimeter, Burette
Maintenance Supplies (ID 4444) - Mop, Broom, Dustpan, Trash Bag, Trash can, Hand soap, Paper towel, Gloves, Floor Cleaner, Cleaning Cloth
Furnitures (ID 5555) - Drafting Table, Computer Desk, Book Shelf, Drawing stool, Bench, Monoblock, Library Desk, Long table, Desk Chair, Tandem Seating

For the ID part, it works like this 1111 then 0001
the last 4 digits depends on the item added
Example:
Table should look like this:
Appliances Aircon 5 2:24 - 04/11/24 1111 0001 editable description through table checkbox
Appliances Aircon 5 2:24 - 04/11/24 1111 0002 editable description through table checkbox
Funitures  Drafting Table  5 2:24 - 04/11/24 2222 0001 editable description through table checkbox
Funitures  Drafting Table  5 2:24 - 04/11/24 2222 0002 editable description through table checkbox

for the description part, the user can double click it so he can input anything in it
the user can also double click the quantity so he can edit it
for the checkbox, the user can tick multiple checkbox

there will be a remove button below the table so the items checked in the checkbox can be removed.
above it is another dropbox that filters out the category in the table to be shown
there is also a date specifier beside it to filter out the date in the table to be shown
the save button's purpose is to save the edits done in the table (particularly quantity, and description)
