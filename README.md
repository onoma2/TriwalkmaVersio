# TriwalkmaVersio

Conjuring up to three walkamas with a Wand



An attempt to imagine what would happen if Nick Reinhard of Tera Melos would smash Instruo Lubdah and Make Noise Morphagene into mtl.asm Count to 5 enclosure to show off his microsound skills to the Knobs of the same YouTube channel. 
Many things will get destroyed in the process, but some more will stay and prosper.

If some tape emulating skwemorphs attempt to recreate a vintage studio feel with saturation, real-time editing and an image of a big and expensive reel, Triwalkma was imagined as an homage to portable cassette players that are used at
The moment as stand alone voices and texture generators, providing tactile feel to the short recordings that are looped on a cut out tape. 

Triwalkma is a broken trio of stereo “walkmas” that continuously record signal and you can only control the destination of recordings but not the mix of the them by the WAND. 

.

![](https://github.com/onoma2/TriwalkmaVersio/blob/main/triwalkma.png)


The panel also depicts "init state" – equal pitch across the looped*3 and input audio, continuous recording, in-to-3 configuration.


###Controls###

The module will respond to +0-5v into the CV inputs. Pots work as offsets. Tap/FSU input (bottom left) of your Versio expects gates or triggers.



- **Blend** – dry/wet mix 
- **Regen** - respective feedback mix of all the walkmas
- **Dub** – overdub %, should create too much volume increase over its course, but I wouldn't recommend keeping it open for the long time without supervision.

**__walkmas__ **

**left, mid, right** – well this is the "varispeed" you craved. From 1/4 to *2. Back or forth.
(Speed of ~1 (aka _original sound pitch_) across all the Walkmas is achieved by the following steps:
1) move left, mid and right to maximum. Then slowly decrease/rotate the the left knob CCW while looking on the right pair of LEDs. At when the speed crosses 1 the left led of the right pair will turn bright green. You are looking for that moment on the virtual cassette tape. Original pitch is near the border. The closer you get the more original it is. There is no dent on the controller, you should not pretend that you have enough precision to catch it.
2) Right walkma can be "tuned" the same way. 
3) Mid one also follows the same scale but both the leds will start blinking milder when all the three knobs are around original speed/pitch. 
The panel picture shows approximate positions.

**WAND** 

Is used to crossfade(top switch on) or switch(top switch gate or tap) the recording destination between walkmas. Point the knob to the left - and the audio will be looped there, move it slowly across the range and you will have bits of recording spread across three virtual cassettes.



**switches**

- __top__ "recording state"

(Left pair of leds turn bright green when recording is on. In tap and gate mode dim green light shows where the Wand is pointing, with both LEDs corresponding to mid)

- **gate** recording is active only when button is pressed or the gate is high in the tap/FSU input. (Wand switches on recording in lefrmost, noon, and rightmost positions to respective
Walkmas)
- always **on** (wand crossfades)
- **tap** record starts on the first tap and ends on the second. (Wand works
As in gate mode)

- __bottom__ "walkmas configuration 
At
- ** Y ** Input to mid. Mid to left and right.
- ** 3 ** input to three walkmas
- ** > ** input to left. Left to mid. Mid to right.


That's it. Have fun. Take care of your ears. Use it at your own risk.

If there will be updates, they will be minor, interface related. 

So please welcome Triwalkma Versio as your new eurorack instrument.


To install it grab the .bin file and flash your Versio module with Ewout Decraene the one that ends .bin and then flash your Versio module with
https://electro-smith.github.io/Programmer/
