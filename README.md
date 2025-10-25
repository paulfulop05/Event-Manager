# Event Manager

Beautiful, small desktop application for managing events. This project demonstrates a clean separation between UI and business logic using C++ and Qt, implements undo/redo with the Command pattern, and shows a custom Qt Model/View table for the user's event list.

## Highlights

- Undo / Redo (multi-step) for add / remove / update operations using a command hierarchy.
- Separate Admin and User workflows (Admin can change the master event list; User can add events to their personal list and export it).
- The user list is displayed with a Qt Model/View (`QAbstractTableModel` + `QTableView`).
- Export to CSV and HTML viewer exporters are included for the user's event list.

## Features

- Add, remove, update events (Admin mode).
- Browse, filter and add events to a personal user list (User mode).
- Multiple-level Undo and Redo for add/remove/update actions (GUI buttons and keyboard shortcuts, e.g. Ctrl+Z / Ctrl+Y). You can press Ctrl+Z to undo and Ctrl+Y to redo.
- Persistent file-based repository (text files for events and user lists) and an in-memory repository implementation for testing.
- Export user list to CSV and HTML and open the exported file in an external viewer from the app.

## Architecture and key components

- `Event` — core domain object representing an event (title, description, date/time, attendees or other fields depending on assignment specifics).
- `Repository` / `FileRepository` / `MemoryRepository` — abstract repository and concrete implementations used by service layer.
- `ServiceAM` / `ServiceUM` — service layer classes that encapsulate business rules for Admin (AM) and User (UM) operations.
- `Command` / `AddCommand` / `RemoveCommand` / `UpdateCommand` — command objects used to implement undo/redo logic. `CommandManager` orchestrates stacks of executed and undone commands.
- `EventsTableModel` — a `QAbstractTableModel` subclass used to present the user's event list in a `QTableView`.
- `AdminForm` / `UserForm` / `MainWindow` — Qt UI forms and controllers for administration, user actions and the main application window.
- `CSVEventViewer` / `HTMLEventViewer` — helpers to export and present the user's list.
- `Tests.cpp` — unit tests exercising core logic (services, repository and validators).

## Getting started — build & run (Windows)

Prerequisites

- Qt (Qt 6 recommended) and a compatible C++ toolchain (MSVC via Visual Studio or MinGW).
- Visual Studio (recommended) or Qt Creator.

Build with Visual Studio

1. Open `LifeAfterSchool.sln` in Visual Studio.
2. Configure the appropriate Qt kit and your target (e.g., x64 Debug/Release).
3. Build the solution and run the `LifeAfterSchool` project.

Build with Qt Creator

1. Open the project folder in Qt Creator.
2. Configure a kit that points to your Qt installation and an appropriate compiler.
3. Build and run from Qt Creator.

Quick run (after a successful build)

The built executable is typically under the solution build folder, for example:

`LifeAfterSchool/x64/Debug/LifeAfterSchool.exe`

You can also run the app from your IDE's run/debug toolbar.

## Usage (brief)

- Launch the app. The `MainWindow` exposes Admin and User workflows.
- Admin: add, remove or update events using the administration form. Each change is recorded as a command and can be undone/redone.
- User: browse events and add them to your personal list. View the personal list in a table (custom model). Export to CSV or HTML and open the exported file in your system viewer.
- Undo/Redo: use the toolbar buttons or keyboard shortcuts (commonly Ctrl+Z / Ctrl+Y).
- Delete a user event: in the user's events table you can delete an event by double-clicking the row for that event (this will remove it from your personal list).

## Running tests

There is a `Tests.cpp` file containing unit tests for core components. If your solution includes a test target, build and run that target from your IDE. Otherwise, compile and run tests as a small console target to exercise the service and repository logic.

## Files of interest

- `Event.*` — domain model
- `Repository.*`, `FileRepository.*`, `MemoryRepository.*` — persistence layer
- `ServiceAM.*`, `ServiceUM.*` — service layer
- `Command*` and `CommandManager.*` — undo/redo implementation
- `EventsTableModel.*` — Qt model for the table view
- `AdminForm.*`, `UserForm.*`, `MainWindow.*` — UI forms and controllers
- `CSVEventViewer.*`, `HTMLEventViewer.*` — exporters/viewers

## Design notes & rationale

This project demonstrates applying well-known patterns in desktop GUI development:

- Command pattern for encapsulating operations and enabling multi-level undo/redo.
- Repository + Service layers to separate persistence, validation and business rules from UI code.
- Qt Model/View architecture for scalable and efficient GUI lists/tables.

These choices make the application easier to test and extend — for example, adding a different persistence backend or an online sync feature would not require major UI changes.

## Contribution and license

This repository is for coursework. See the `LICENSE` file in the project root for license details. If you want to extend the project, open an issue or submit a pull request with a small, focused change.
