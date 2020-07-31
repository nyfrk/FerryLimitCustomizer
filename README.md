# The Settlers 4: Ferry Limit Customizer

By default, you can only embark at most 15 settlers on your ferries. This script enables you to customize this value.

There is a [German translation for this README](README_DE.md). Please note that it may be outdated.



## Features

* Change the ferry capacity to 45 settlers.
* You can customize the limit by using a configuration file.
* Compatibility: Works with the Gold Edition and the History Edition of The Settlers 4.



## How to use

You need an ASI Loader to use this mod. I recommend [The Settlers 4: ASI Loader](https://github.com/nyfrk/Settlers4-ASI-Loader) as it works nicely with the Gold and History Edition of The Settlers 4 and does not require any configuration. 

1. [Download](https://github.com/nyfrk/FerryLimitCustomizer/releases) a release.
2. Unpack the files into your `plugins` directory.
3. Start the game. The mod will load automatically.

To uninstall the mod remove `FerryLimitCustomizer.asi` from your`plugins` directory. 

### Customize

Open the FerryCustomizer.ini to change the limit to any value you desire.



## Known Problems

* Multiplayer interoperability: **All participants in a multiplayer session must use this mod with an identical configuration file**. Otherwise the game will DESYNC. 



## Issues and Questions

The project uses the Github Issue tracker. Please open a ticket [here](https://github.com/nyfrk/FerryLimitCustomizer/issues). 



## Contribute

The official repository of this project is available at https://github.com/nyfrk/FerryLimitCustomizer. 

#### Compile it yourself

Download Visual Studio 2017 or 2019 with the C++ toolchain. The project is configured to build it with the Windows XP compatible **v141_xp** toolchain. However, you should be able to change the toolchain to whatever you like. No additional libraries are required so it should compile out of the box.



## License

The project is licensed under the [MIT](LICENSE.md) License. 
