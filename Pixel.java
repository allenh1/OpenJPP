/**
 * Pixel Class
 *
 * This class represents a pixel as a single 32-bit integer.
 * The integer is comprised of four eight-bit values.
 */

public class Pixel {
	private int pixel;

    public Pixel(int pixel) {
		this.pixel = pixel;
	}

	/**
	 * Returns the red channel of the pixel.
	 *
	 * Shifts the integer 16 bits and masks it to the max 255.
	 */
	public int getRed() {
		return pixel >> 16 & 0xff;
	}

	public int getGreen() {
		return (pixel >> 8) & 0xff;
	}

	public int getBlue() {
		return pixel & 0xff;
	}

	public void setRed(int red) {
		red = red & 0xff; //garuntee the value is in rang;
		int shifted = ~((0xff) << 16);	
		pixel = pixel & shifted;
		pixel = pixel | (red << 16);
	}

	public void setGreen(int green) {
		green = green & 0xff;
		int shifted = ~((0xff) << 8);		
		pixel = pixel & shifted;
		pixel = pixel | (green << 8);
	}

	public void setBlue(int blue) {
		blue = blue & 0xff;
		int shifted = ~0xff;
		pixel = pixel & shifted;
		pixel = pixel | (blue);
	}

	public static void main(String[] args) {
		Pixel p1 = new Pixel (0xFFFF00FF);
		    
		Pixel p2 = new Pixel(0xFF43BF11);

		Pixel p3 = new Pixel(0xFF000000);

		int newRed = 12;
		int newGreen = newRed * 4;
		int newBlue = newRed / 12;
		newBlue = newBlue * 100;
		newBlue = newBlue / 32;

		p3.setRed(newRed);
		p3.setGreen(newGreen);
		p3.setBlue(newBlue);
		System.out.printf("rgb = (%d, %d, %d)\n", p3.getRed(), p3.getGreen(), p3.getBlue());
	}
}