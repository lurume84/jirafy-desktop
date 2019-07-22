# Jirafy desktop
This application is the container of [Jirafy Viewer](https://github.com/lurume84/jirafy-viewer) project. It is a chrome-based application (CEF) that loads viewer seamlessly and provides local storage capabilities.

## What it does

* Upgrades to last official Jirafy Viewer automatically
* Disables CORS to allow connection with Jira Servers

## What it will do


## Installation
Just go to Releases section and download last Jirafyetup.exe installer. It will create a shortcut to the installation folder %localappdata%/Jirafy Desktop.

## Usage
This application automatically creates folder %userprofile%/Documents/Jirafy.exe. This folder contains all user-related information that is described below

### CrashReports
In case application crashes, a dump will be generated inside this folder. If you want to contribute to its resolution send it to me.

### Download
Videos, Thumbnails and github releases will be downloaded here. To force a redownload of viewer just delete versions folder and open application again.

### Html
Contains the downloaded viewer. This is automatically stepped over by viewer updates, also contains your connection token. In case you want to remove credentials remove token.json file.

### Jirafy.ini
This is the file you need to modify to configure your desktop application.

## Development Guide
You need vs2017. Checkout and uncompress third_party.7z in the same folder.

## Compatibility
Only Windows 10 is fully supported at this time due to Toast Notifications. Windows 7 also works but without notifications system. In practice, this only means you need to manually update viewer by deleting %userprofile%/Documents/Jirafy.exe/Html/viewer folder and starting application again.
