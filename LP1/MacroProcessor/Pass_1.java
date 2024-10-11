package MacroProcessor;

import java.io.*;

class Solution {

    BufferedReader input;
    BufferedWriter MNT;
    BufferedWriter MDT;
    BufferedWriter temp;
    BufferedWriter IC;

    int mntc;
    int mdtp;

    public Solution() throws IOException {

        input = new BufferedReader(new FileReader("D:\\Avdhoot\\GitHub\\AG1713\\Practicals\\LP1\\MacroProcessor\\input"));
        MNT = new BufferedWriter(new FileWriter("D:\\Avdhoot\\GitHub\\AG1713\\Practicals\\LP1\\MacroProcessor\\MNT"));
        MDT = new BufferedWriter(new FileWriter("D:\\Avdhoot\\GitHub\\AG1713\\Practicals\\LP1\\MacroProcessor\\MDT"));
        IC = new BufferedWriter(new FileWriter("D:\\Avdhoot\\GitHub\\AG1713\\Practicals\\LP1\\MacroProcessor\\IC"));

        mntc = 0;
        mdtp = 0;

    }


    public void generateOutput() throws IOException {
        String card = input.readLine();

        while (!card.contains("START")){
            if (!card.equals("MACRO")){
                card = input.readLine();
                continue;
            }

            card = input.readLine();
//            card.replaceAll("[&,]","");
            String[] parts = card.split("\\s+");
            // "\\s+" denotes any number of spaces

            MNT.write(parts[0] + "\t" + mdtp + "\n");
            MNT.flush();

            temp = new BufferedWriter(new FileWriter("D:\\Avdhoot\\GitHub\\AG1713\\Practicals\\LP1\\MacroProcessor\\ALA_" + parts[0]));

            for (int i=1 ; i<parts.length ; i++){
                if (parts[i].contains("=")){
                    String[] s = parts[i].split("=");
                    temp.write(s[0]);
                    temp.flush();
                    continue;
                }

                temp.write(parts[i] + "\n");
                temp.flush();
            }

            while (true) {
                card = input.readLine();
                mdtp++;

                if (card.equals("MEND")){
                    MDT.write("MEND\n");
                    MDT.flush();
                    break;
                }

                MDT.write(card + "\n");
                MDT.flush();
            }

            card = input.readLine();
        }

        // The card now contains START
        while (!card.equals("END")){
            IC.write(card + "\n");
            IC.flush();
            card = input.readLine();
        }
        IC.write("END");
        IC.flush();

    }

}

public class Pass_1 {


    public static void main(String[] args) {
        try {
            Solution s = new Solution();
            s.generateOutput();

        }
        catch(IOException e){
            System.out.println("File error : " + e.getMessage());
        }
    }


}
