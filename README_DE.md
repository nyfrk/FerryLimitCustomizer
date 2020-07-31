# Die Siedler 4: Fährenlimit Customizer

Standardmäßig können maximal nur 15 Siedler eine Fähre besteigen. Dieses Script erlaubt es dir das Limit beliebig zu verändern.

Für dieses README gibt es eine [englische Version](README.md). Bitte beachte, dass die deutsche Übersetzung ggf. veraltet sein kann.



## Features

* Erhöht die Kapazität von Fähren von 15 auf 45.
* Das Limit ist über eine Konfigurationsdatei einstellbar.
* Kompatibilität: Die Mod läuft sowohl mit der Gold Edition als auch der History Edition von Die Siedler 4.



## Installation

Du benötigst einen ASI Loader um die Mod zu nutzen. Ich empfehle den [The Settlers 4: ASI Loader](https://github.com/nyfrk/Settlers4-ASI-Loader), da er gut mit der Gold und History Edition von Die Siedler 4 funktioniert und keinerlei Konfiguration erfordert. 

1. Lade eine Version des [Fährenlimit Customizers](https://github.com/nyfrk/FerryLimitCustomizer/releases) herunter.
2. Entpacke die Dateien in dein `plugins` Verzeichnis.
3. Starte das Spiel. Die Mod sollte nun automatisch geladen werden.

Um die Mod zu deinstallieren, entferne die `FerryLimitCustomizer.asi` aus dem `plugins`-Verzeichnis. Wenn 

### Customize

Öffne die FerryCustomizer.ini um das Limit nach belieben anzupassen.



## Bekannte Probleme

* Mehrspieler-Interoperabilität: **Alle Teilnehmern einer Multiplayer-Session müssen die Mod mit der selben Konfiguration nutzen**. Andernfalls kommt es zu DESYNCs.



## Probleme und Fragen

Das Projekt verwendet den Github Issue Tracker. Bitte öffne [hier](https://github.com/nyfrk/FerryLimitCustomizer/issues) ein Ticket für dein Anliegen. 



## Mitmachen

Das offizielle Repository dieses Projekts ist unter https://github.com/nyfrk/FerryLimitCustomizer verfügbar. 

##### Kompilieren

Lade Visual Studio 2017 oder 2019 mit der C++-Toolchain herunter. Das Projekt ist so konfiguriert, dass es mit der Windows XP-kompatiblen **v141_xp**-Toolchain gebaut wird. Du solltest jedoch die Toolchain nach Belieben ändern können. Es sind keine zusätzlichen Bibliotheken erforderlich, sodass das Projekt ohne weiteres gebaut werden kann. 



## Lizenz

Das Projekt ist unter der [MIT](LICENSE.md)-Lizenz lizenziert. 
