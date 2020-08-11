# AutoRun
 Ultra simple autorun (sprint) for playing games that don't implement it

## How to use

* Go in game settings and put Sprint key on P.
* Run AutoRun executable

it will start to simulate P as if it was pressed : your character will sprint.
When you press Shift, it will release P : your character won't sprint anymore.

## How does it work

It simply uses SendInput ( [from Windows API](https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-sendinput) ) to synthesizes keystrokes.

IT DOES NOT INTERACT WITH THE GAME
