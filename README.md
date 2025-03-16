# Dental Insurance Payer Processing System

## Overview

This project is a **Flask-based web application** designed to process and manage **dental insurance payer data**. It allows users to upload Excel files, perform payer mappings, manage hierarchical relationships, and update payer display names. The system categorizes payers into groups and provides an administrative interface for manual adjustments.

## Features

- **Upload and process Excel files** containing payer details.
- **Automatic mapping** of payers using semantic similarity and existing records.
- **Manual mapping interface** for admins to adjust payer details.
- **Hierarchical payer management**, linking payers to groups.
- **Pretty name customization** for better display.
- **Web-based UI** for managing and viewing payer details.

## Tech Stack

- **Backend:** Flask, Flask-WTF (Forms), Flask-SQLAlchemy
- **Database:** SQLite
- **Frontend:** HTML, CSS, Jinja2 templates
- **Libraries:** Pandas (for Excel processing), difflib (for string similarity matching)

## Installation

### 1. Clone the repository

```bash
git clone <repo_url>
cd <project_directory>
```

### 2. Set up a virtual environment (optional but recommended)

```bash
python -m venv venv
source venv/bin/activate  # On Windows use `venv\Scripts\activate`
```

### 3. Install dependencies

```bash
pip install -r requirements.txt
```

### 4. Run the application

```bash
python app.py
```

The application will start at `http://127.0.0.1:5000/`.

## Project Structure

```
├── app.py              # Main application entry point
├── mapping.py          # Excel data processing & payer mapping logic
├── models.py           # Database models
├── templates/          # HTML templates
│   ├── base.html
│   ├── index.html
│   ├── payer_groups.html
│   ├── payer_details.html
│   ├── admin_mapping.html
│   ├── admin_pretty_names.html
│   ├── admin_hierarchy.html
├── static/             # CSS & JS files
```

## Usage Guide

### Uploading Data

1. Navigate to the **Upload** page.
2. Select an **Excel file (.xlsx)** containing payer details.
3. Click **Upload and Process** to store the data in the database.

### Managing Payers

- **Payer Groups:** View payers categorized by group.
- **Manual Mapping:** Manually assign a payer detail to an existing payer.
- **Pretty Names:** Customize the display name of a payer.
- **Hierarchy Management:** Assign payers to specific groups.

## Data Processing Flow

1. **Excel Upload** → Parses different sheets into `PayerDetail` records.
2. **Automated Mapping** → Uses string similarity to match existing payers.
3. **Database Storage** → Stores payers in structured `Payer`, `PayerGroup`, and `PayerDetail` tables.
4. **Admin Adjustments** → Admins can manually update mappings via UI.

## Future Enhancements

- Support for additional file formats (CSV, JSON)
- Improved payer matching using ML-based similarity scoring
- User authentication for admin controls
- API endpoints for external integrations

## License

This project is open-source under the **MIT License**.

## Author

Developed by [Your Name]. Feel free to contribute!

