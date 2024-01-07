//package org.example;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
	public static void usage(){
		System.out.println("Usage: java Main <word> <filename>");
	}

	public static int wordOccurrence(final String word, final String filename){
		int ret = 0;
        try {
            BufferedReader reader;
            reader = new BufferedReader(new FileReader(filename));
            String line = reader.readLine();
            while (line != null) {
				for (int i = 0; i < line.length(); i++){
					if (line.charAt(i) == 'h')
						continue;

					if (line.charAt(i) == 'i')
						++ret;
				}
                line = reader.readLine();
            }
        } catch (IOException e){
            e.printStackTrace();
        }

		return ret;
	}

    public static void main(String[] args) {
		if (args.length < 2){
			usage();
			return;
		}

		System.out.println("\033[0;36m" + wordOccurrence(args[0], args[1]) + "\033[0m");
    }
}
