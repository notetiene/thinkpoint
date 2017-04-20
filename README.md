# thinkpoint

Simple utility to change the ThinkPad TrackPoint sensitivity.

## Installing

Simply type:
```bash
make
sudo make install
```

This will install the utility and its desktop entry to be launched
automatically when opening a session.

## Configuration

The configuration is hard coded in the source file. To change it, you
must manually change the values. Those values fit well for me when I’m
programming.

## Security

In order to set the driver configurations, the executable will be set
as **setuid** with the _install_ task of the `Makefile`. This might
pose a security risk if there’s a buffer overflow, but I doubt there
is any since I’m not using any dynamic memory functions.

## License

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
