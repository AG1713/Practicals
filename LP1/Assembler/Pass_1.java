package Assembler;

import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;

class MnemonicEntry{
    String mnemonicClass;
    String opcode;

    public MnemonicEntry(String mnemonicClass, String opcode) {
        this.mnemonicClass = mnemonicClass;
        this.opcode = opcode;
    }
}
class Token{
    String name;
    String tokenClass;
    String address;
}


class Solution {
    HashMap<String, MnemonicEntry> MOT;
    ArrayList<Token> symbolTable;
    ArrayList<Token> literalTable;
    BufferedReader input;
    BufferedWriter output;
    int LC;

    Solution(){
        MOT = new HashMap<>();
        symbolTable = new ArrayList<>();
        literalTable = new ArrayList<>();
        // Opening input and output files
        try {
            input = new BufferedReader(new FileReader("D:\\Avdhoot\\GitHub\\AG1713\\Practicals\\LP1\\Assembler\\Input"));
            output = new BufferedWriter(new FileWriter("D:\\Avdhoot\\GitHub\\AG1713\\Practicals\\LP1\\Assembler\\Intermediate_code"));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        MOT.put("STOP", new MnemonicEntry("IS", "00"));
        MOT.put("ADD", new MnemonicEntry("IS", "01"));
        MOT.put("SUB", new MnemonicEntry("IS", "02"));
        MOT.put("MULT", new MnemonicEntry("IS", "03"));
        MOT.put("MOVER", new MnemonicEntry("IS", "04"));
        MOT.put("MOVEM", new MnemonicEntry("IS", "05"));
        MOT.put("COMP", new MnemonicEntry("IS", "06"));
        MOT.put("BC", new MnemonicEntry("IS", "07"));
        MOT.put("DIV", new MnemonicEntry("IS", "08"));
        MOT.put("READ", new MnemonicEntry("IS", "09"));
        MOT.put("PRINT", new MnemonicEntry("IS", "10"));

        MOT.put("START", new MnemonicEntry("AD", "01"));
        MOT.put("END", new MnemonicEntry("AD", "02"));
        MOT.put("ORIGIN", new MnemonicEntry("AD", "03"));
        MOT.put("EQU", new MnemonicEntry("AD", "04"));
        MOT.put("LTORG", new MnemonicEntry("AD", "05"));

        MOT.put("DS", new MnemonicEntry("DL", "01"));
        MOT.put("DC", new MnemonicEntry("DL", "02"));

        MOT.put("AREG", new MnemonicEntry("RG", "01"));
        MOT.put("BREG", new MnemonicEntry("RG", "02"));
        MOT.put("CREG", new MnemonicEntry("RG", "03"));

        MOT.put("EQ", new MnemonicEntry("CC", "01"));
        MOT.put("LT", new MnemonicEntry("CC", "02"));
        MOT.put("GT", new MnemonicEntry("CC", "03"));
        MOT.put("LE", new MnemonicEntry("CC", "04"));
        MOT.put("GE", new MnemonicEntry("CC", "05"));
        MOT.put("NE", new MnemonicEntry("CC", "06"));
        MOT.put("ANY", new MnemonicEntry("CC", "07"));
    }

    void generateIntermediateCode() throws IOException {
        String card = input.readLine();
        if (!card.startsWith("START")) return; // If it does not start with start
        String[] parts = card.split(" ");
        LC = Integer.parseInt(parts[1]);

        // Reading second line (Non-start)
        card = input.readLine();
        parts = card.split(" ");

        while (!card.equals("END")){
            LC++;


            if (MOT.containsKey(parts[0])){
                MnemonicEntry mnemonicEntry = MOT.get(parts[0]);
                output.write("(" + mnemonicEntry.mnemonicClass + "," + mnemonicEntry.opcode + ")");




            }


            card = input.readLine();
            parts = card.split(" ");
        }



    }





}



public class Pass_1 {


}
