stigame tasks
=======
RoadMap to 0.1.0
This are the tasks that are need to be done for the first minor release of StiGame.

### Gui Module

- [ ] Write a Table Test Program and find the issues with the current Table Class
- [ ] Progress Bar Test and fixes
- [x] BaseClass for Font rendering Item
- [x] BaseClass for Caption Item
- [x] Rework Label Class to use CaptionSupport
- [x] Rework Button Class to use CaptionSupport
- [x] Rework Decorated Button Class to use CaptionSupport
- [ ] Rework RadioButton Class to use CaptionSupport
- [x] Rework CheckBox Class to use CaptionSupport
- [ ] Form Layout Implementation
- [ ] GuiItem Effect (Fade In & Out, Shrink, movement)
- [ ] Frame File more robust testing __WIP__
- [x] ItemDefinition modification to apply CaptionSupport changes
- [ ] Investigate Effect problem with new CaptionSupport

### Core Module

- [x] Viewport resolution and settings to be saved into a configuration file
- [ ] Float Matrix Operation

### Network Module

- [x] PacketStream Short and UShort data type
- [ ] PacketStream Long and ULong data type
- [x] PacketStream Bool type
- [ ] Need to test packet transfert little endian vs big endian
- [ ] TcpSocket Implementation
- [ ] Packet Implementation for TcpSocket
- [ ] MessageQueue System Base Class with multi-thread, sending and receiving thread

### Build Generation
- [ ] Fix Windows Build (probably need to include winpthread)

### Documentation
- [ ] Generate a more recent Doxy API Documentation
- [ ] Write some little tutorials on GameState and Event Handling
- [ ] Website

