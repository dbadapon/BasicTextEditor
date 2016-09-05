# BasicTextEditor
This is a dramatically simplified version of a text editor like like vim or emacs, completely based around a textual interface that runs in a Linux shell window.
</br>
<p>The text editor you'll be implementing in this project is called <b>BooEdit</b>.  It's a dramatically simplified version of an editor like <b>vim</b> or <b>emacs</b>, completely based around a textual interface that runs in a Linux shell window.  When running, BooEdit looks like this:</p>

<blockquote><pre>
16 |It was just a glimpse of you, like looking through a window
17 |Or a shallow sea
18 |Could you see me?
19 |And after all this time&#x25a0;
20 |It's like nothing else we used to know
21 |After all the hangers-on are done hanging on to the dead lights
22 |Of the afterglow
23 |I've gotta know
24 |
25 |Can we work it out?
26 |Scream and shout 'till we work it out?
    ----------------------------------------------------------------------
                                                              Ln 19 Col 24
</pre></blockquote>

<p>At any given time, the lion's share of the space is dedicated to the text being edited, which we'll call the <i>editor area</i>.  A cursor is displayed somewhere in that area &mdash; depicted above as a black square &mdash; and the location of the cursor, relative to the entire text being edited, is indicated in the bottom-right corner.  Line numbers are displayed along the left-hand edge of the window.  Because the text may be longer than the available space in the editor area, the text scrolls vertically and horizontally as necessary, so that the cursor will always be visible in the editor area.  Occasionally, short error messages are displayed (e.g., when trying to move the cursor above the topmost line of the text); in that case, the error messages are shown just below the dashes under the last line of text (so, in the example above, they would be displayed just below the words <b>Scream and shout</b>).</p>

<p>BooEdit always launches with no text in the editor.  It supports neither loading of text files nor saving of them.</p>

<p class="subtitle">Giving input to BooEdit</p>

<p>The only way to provide input to BooEdit is via the keyboard.  To maintain maximum compatibility with everyone's setup &mdash; you may be using any number of ways of connecting to your VM (e.g., using the ICS 45C VM's GUI in VirtualBox, via SSH through PuTTY on Windows or a Terminal window on a Mac), BooEdit is quite conservative about what keys it pays attention to, because special keys (like function keys, arrow keys, <b>Home</b>, <b>End</b>, etc.) are not handled consistently across systems.  So the only keys that BooEdit officially supports are these:</p>

<ul>
  <li><i>Printable characters</i> in the ASCII character set (those with ASCII codes between 32 and 126), a list of which you can find many places online.</li>
  <li><i>Control characters</i>, meaning the characters you get when you hold down the <b>Control</b> key on your keyboard and press a letter (A through Z).</li>
</ul>

<p>Other keys may be ignored or may trigger other strange behavior, but this is not something we'll be concerned with in this project.  (You can feel free to add support for anything else you'd like, but we'll be testing only with what's listed below.)</p>
