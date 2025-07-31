📘 Infobook

Infobook is a lightweight personal information manager built in pure C, optimized for resource-constrained environments. It’s designed to help users store, search, and manage basic identity records efficiently, making it especially useful in offline-first contexts like MSMEs, rural outreach setups, or embedded deployments.

## 🎯 Why Infobook?

- ⚡ **Fast & Lightweight:** Minimal overhead, runs instantly from a `.exe` or compiled binary.
- 📴 **Offline-First:** Requires no internet connection or external dependencies.
- 🛠️ **Built with C:** Rock-solid performance and full transparency in logic and memory management.
- 🧰 **Extendable Foundation:** Future-ready for mesh sync, UI overlay, or encrypted storage.

## 🚀 Features

- Add and store user details (e.g., name, phone, ID)
- View and search entries with basic filters
- Modify existing data
- Save/load info from a `.txt` file
- Modular code structure via header and function files

## 🗂️ File Structure

| File              | Description                                    |
|------------------|------------------------------------------------|
| `main.c`         | Program entry point and flow control           |
| `infobook_fn.c`  | Core functions for data handling               |
| `infobook_fn.h`  | Function declarations                          |
| `info.txt`       | Sample data file for saved entries             |
| `main.exe`       | Compiled executable for Windows users          |

## 🖥️ Usage

### 🧪 Compile Manually
```bash
gcc main.c infobook_fn.c -o infobook
./infobook
