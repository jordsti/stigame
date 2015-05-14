stigame tasks
=======
RoadMap to 0.1.0
This are the tasks that are need to be done for the first minor release of StiGame.

### Gui Module

- [ ] Write a Table Test Program and find the issues with the current Table Class __WIP__
- [x] Progress Bar Test and fixes
- [x] BaseClass for Font rendering Item
- [x] BaseClass for Caption Item
- [x] Rework Label Class to use CaptionSupport
- [x] Rework Button Class to use CaptionSupport
- [x] Rework Decorated Button Class to use CaptionSupport
- [x] Rework RadioButton Class to use CaptionSupport
- [x] Rework CheckBox Class to use CaptionSupport
- [ ] Form Layout Implementation __WIP__ to test
- [ ] Write a FormLayout Test Apps
- [ ] GuiItem Effect (Fade In & Out, Shrink, movement) __WIP__ Shrink is bugged
- [ ] Frame File more robust testing __WIP__ Need to add Table Support
- [x] ItemDefinition modification to apply CaptionSupport changes
- [x] Investigate Effect problem with new CaptionSupport
- [ ] Table Event (ClickCellEvent and maybe other event type) __WIP__
- [ ] Implement a Spinner, with new arrow (omg need to add attributes to style again..)
- [ ] Style File using var file
- [x] TableRow, attach a ValueObject to a row
- [x] Table Clear Rows w/ clear columns as well

### Core Module

- [x] Viewport resolution and settings to be saved into a configuration file
- [ ] Float Matrix Operation _can be postponed_

### Network Module

- [x] PacketStream Short and UShort data type
- [x] PacketStream Long and ULong data type
- [x] PacketStream Bool type
- [ ] Need to test packet transfert little endian vs big endian
- [ ] TcpSocket Implementation __WIP__ need testing
- [ ] Packet Implementation for TcpSocket __WIP__ need testing
- [x] MessageQueue System Base Class with multi-thread, sending and receiving thread
- [ ] Converting all stream int read & write with SDLNet_Write|Read __WIP__

### Build Generation
- [x] Fix Windows Build (probably need to include winpthread) (SDL_Detach not defined)

### Documentation
- [ ] Generate a more recent Doxy API Documentation
- [ ] Write some little tutorials on GameState and Event Handling
- [ ] Website

