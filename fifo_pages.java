import java.io.*;
import java.lang.*;
import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("Enter number of pages");
		int pages = in.nextInt();
		System.out.println("Enter number of frames");
		int frames = in.nextInt();
		int[][] fifo = new int[pages+1][frames+2];

		/*
		Pages index 0 stores the frames
		Frames start at index 1 and end at index [frames] index 0 stores individual pages and index [frames+1] stores hit or miss

		Frames 	___
		pages    |
		*/
		System.out.println("Enter pages");
		for (int i = 1 ; i <= pages ; i++ ) {
			fifo[i][0] = in.nextInt();
		}
		System.out.println("Enter frames");
		for (int i = 1 ; i <= frames ; i++ ) {
			fifo[0][i] = in.nextInt();
		}

		for ( int i = 1 ; i <= frames ; i++ ) {
			for( int j = 1 ; j <= pages ; j++) {
				fifo [j][i] = -6969;
			}
		}
		for ( int i = 1 ; i <= frames ; i++ ) {
			for( int j = 1 ; j <= pages ; j++) {
				if( fifo[j][i] == -6969 ) {
					fifo[j][i] = fifo[j][0];
					fifo[j][frames+1] = 1 ;
					if(i<frames)
						i++;
					else
						i=1;
				}
				else{
					if(fifo[j][0]==fifo[j][i]){
						fifo[j][frames+1] = 0;
					}
					else{
						fifo[j][i] = fifo[j][0];
						fifo[j][frames+1] = 1 ;
						if(i<frames)
							i++;
						else
							i=1;
					}

				}

			}
		}

		//printing

		for (int i = 0 ;i < frames+2; i++ ) {
			for (int j = 0 ; j < pages+1 ; j++ ) {
				System.out.print(" "+fifo[j][i]+" ");
			}
			System.out.println();
		}

	}
}