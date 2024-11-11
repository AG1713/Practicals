package MacroProcessor;

import java.io.*;
import java.util.*;

class SolutionPass2 {

    BufferedReader input; // Input from pass-1 output
    BufferedReader MNT_file;
    BufferedReader MDT_file;
    BufferedWriter output; // Final output file after macro expansion

    Map<String, Integer> MNT = new HashMap<>(); // Macro name and MDT pointer
    ArrayList<String> MDT = new ArrayList<>(); // Stores all MDT lines

    public SolutionPass2() throws IOException {
        input = new BufferedReader(new FileReader("D:\\Avdhoot\\GitHub\\AG1713\\Practicals\\LP1\\MacroProcessor\\IC")); // Pass-1 output file
        MNT_file = new BufferedReader(new FileReader("D:\\Avdhoot\\GitHub\\AG1713\\Practicals\\LP1\\MacroProcessor\\MNT"));
        MDT_file = new BufferedReader(new FileReader("D:\\Avdhoot\\GitHub\\AG1713\\Practicals\\LP1\\MacroProcessor\\MDT"));
        output = new BufferedWriter(new FileWriter("D:\\Avdhoot\\GitHub\\AG1713\\Practicals\\LP1\\MacroProcessor\\Output"));

        loadMNT(); // Load the Macro Name Table
        loadMDT(); // Load the Macro Definition Table
    }

    // Load the Macro Name Table (MNT) from the MNT file
    public void loadMNT() throws IOException {
        String line;
        while ((line = MNT_file.readLine()) != null) {
            // Split by whitespace
            String[] parts = line.split("\\s+");

            // Ensure the line has a valid format (macroName mdtPointer)
            if (parts.length < 2) {
                System.out.println("Malformed MNT entry: " + line);
                continue;
            }

            MNT.put(parts[0], Integer.parseInt(parts[1])); // Macro name and MDT pointer
        }
    }

    // Load the entire MDT into a list (MDTContent)
    public void loadMDT() throws IOException {
        String line;
        while ((line = MDT_file.readLine()) != null) {
            MDT.add(line); // Add all lines of MDT into list
        }
    }

    public void expandMacros() throws IOException {
        String card = input.readLine();
        card = card.replace(",", "");

        while (card != null) {
            String[] parts = card.split("\\s+");

            // If this is a macro invocation
            if (MNT.containsKey(parts[0])) {
                int mdtIndex = MNT.get(parts[0]);
                Map<String, String> ALA = new HashMap<>();

                // Getting parameters from MDT
                BufferedWriter ALA_file = new BufferedWriter(new FileWriter("D:\\Avdhoot\\GitHub\\AG1713\\Practicals\\LP1\\MacroProcessor\\ALA_"+parts[0]));
                String entry = MDT.get(mdtIndex);
                // First entry is macro signature
                // We are adding formal parameter + actual parameter in ALA

                String[] param = entry.split("\\s+");
                for (int i=1 ; i< parts.length ; i++){
                    parts[i] = parts[i].replace(",", "");
                    param[i] = param[i].replace(",", "");
                    ALA.put(param[i],parts[i]);
                    ALA_file.write(param[i] + "\t" + parts[i] + "\n");
                    ALA_file.flush();
                }
                ALA_file.close();

                // Expand the macro body from MDT
                expandMDT(mdtIndex+1, ALA); // +1 since the first statement is its signature
            } else {
                // If not a macro, write the assembly code directly
                output.write(card + "\n");
                output.flush();
            }
            card = input.readLine();
        }

        // Close resources
        output.close();
        MNT_file.close();
        MDT_file.close();
        input.close();
    }

    // Expand the macro using MDT and ALA (Argument List Array)
    // Expand the macro using MDT and ALA (Argument List Array)
    public void expandMDT(int mdtIndex, Map<String, String> ALA) throws IOException {
        String mdtLine;
        while (!(mdtLine = MDT.get(mdtIndex)).equals("MEND")) {
            String[] tokens = mdtLine.split("\\s+");

            for (int i=0 ; i< tokens.length ; i++){
                if (ALA.containsKey(tokens[i].replace(",", ""))) tokens[i] = ALA.get(tokens[i]);
                output.write(tokens[i] + " ");
            }
            output.write("\n");
            output.flush();

            mdtIndex++;
        }
    }

}

public class Pass_2 {

    public static void main(String[] args) {
        try {
            SolutionPass2 s = new SolutionPass2();
            s.expandMacros();
        } catch (IOException e) {
            System.out.println("File error: " + e.getMessage());
        }
    }
}
