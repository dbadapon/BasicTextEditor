# BasicTextEditor
This was a project done in ICS 45C: C++ as a Second Programming Language. 
</br></br>
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

<b>Giving input to BooEdit</b>

<p>The only way to provide input to BooEdit is via the keyboard.  To maintain maximum compatibility with everyone's setup &mdash; you may be using any number of ways of connecting to your VM (e.g., using the ICS 45C VM's GUI in VirtualBox, via SSH through PuTTY on Windows or a Terminal window on a Mac), BooEdit is quite conservative about what keys it pays attention to, because special keys (like function keys, arrow keys, <b>Home</b>, <b>End</b>, etc.) are not handled consistently across systems.  So the only keys that BooEdit officially supports are these:</p>

<ul>
  <li><i>Printable characters</i> in the ASCII character set (those with ASCII codes between 32 and 126), a list of which you can find many places online.</li>
  <li><i>Control characters</i>, meaning the characters you get when you hold down the <b>Control</b> key on your keyboard and press a letter (A through Z).</li>
</ul>

Supported Actions: Insert Character, Ctrl+I: Cursor U, Ctrl+K: Cursor Down, Ctrl+U: Cursor Left, Ctrl+O: Cursor Right, Ctrl+Y:	Cursor Home, Ctrl+P:	Cursor End, Ctrl+J & Ctrl+M: New Line, Ctrl+H: Backspace, Ctrl+D: Delete Line, Ctrl+Z: Undo, Ctrl+A: Redo, Ctrl+X: Quit/Exit.
</br>
The following files were given to start out with:
</br>

<ul>
  <li>There is a <b>main.cpp</b> file, which contains the program's <b>main()</b> function, along with some supporting functions that do some necessary tasks, such as setting up handling for exceptions (and also for signals that the program has crashed, so it can still dismiss the user interface even when there's a crash).</li>
  <li>The <b>BooEdit</b> module implements a class called <b>BooEdit</b>, which implements BooEdit's outermost layer.  An instance of BooEdit is actually a combination of three things:
    <ul>
      <li>An <b>EditorModel</b>, which stores the text editor's underlying data (e.g., the lines of text, the current position of the cursor) and allows it to be manipulated.</li>
      <li>An <b>EditorView</b>, which visualizes the current state of the text editor in some way, e.g., by displaying it in a Linux shell window.</li>
      <li>An <b>InteractionReader</b>, which reads user interfaces, e.g., by waiting for the user to press keys on the keyboard.
    </ul>
    The latter two of those things are implemented as an inheritance hierarchy, with an abstract base class specifying the set of virtual member functions, and derived classes supplying the implementations.  This allows us to do unit testing on BooEdit without a user interface being displayed.  (This is described in more detail below.)</li>
  <li>The <b>EditorModel</b> module implements a class called <b>EditorModel</b>, which is responsible for maintaining and modifying the current state of the editor (the current cursor location, all of the text currently in the editor, and the error message (if any) that should be displayed).  As provided, it contains a handful of member functions that are used to gather enough information to draw the screen, though they're generally implemented as stubs (i.e., their implementations are not correct, but at least compile and run).  You'll need to add additional member functions to this class as you find the need, so you can retrieve and modify the state of the editor.</li>
  <li>The <b>EditorView</b> module provides an abstract base class for views, which implement the "look and feel" of BooEdit.  There are two derived classes of the <b>EditorView</b> class provided: <b>NcursesEditorView</b> and (in your <b>gtest</b> directory) <b>InvisibleEditorView</b>.  You will not need to modify either of these.</li>
  <li>The <b>InteractionReader</b> module provides an abstract base class for reading user interfaces.  There are two derived classes of the <b>InteractionReader</b> class provided: <b>KeypressInteractionReader</b> and (in your <b>gtest</b> directory) <b>MockInteractionReader</b>.  You will not need to modify either of these.</li>
  <li>The <b>Keypress</b> module implements a class called <b>Keypress</b>, which represents the result of a user pressing a key on the keyboard, possible with the <b>Ctrl</b> key depressed.</li>
  <li>The <b>KeypressReader</b> module provides an abstract base class for reading keypresses.  There are two derived classes of <b>KeypressReader</b> provided: <b>NcursesKeypressReader</b> and (in your <b>gtest</b> directory) <b>MockKeypressReader</b>.</li>
  <li>The <b>InteractionProcessor</b> module handles user interactions, waiting for the user to press relevant keys and then executing the corresponding commands.  This is also where the "undo" and "redo" features are to be implemented.  You'll need to make changes here to implement undo/redo and whatever else you find necessary.</li>
  <li><b>Command.hpp</b> declares an abstract base class from which you'll derive classes to implement each command.</li>
  <li>The <b>BooEditLog</b> module provides a logging capability, described in more detail later in this write-up.</li>
</ul>

