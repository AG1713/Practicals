package Assembler1;

import java.io.*;
import java.util.HashMap;

class Solution{
    private String[] IS = {"STOP","ADD","SUB","MULT","MOVER","MOVEM","COMP","BC","DIV","READ","PRINT"};
    private String[] AD = {"","START","END","ORIGIN","EQU","LTORG"};
    private String[] DL = {"","DS","DC"};
    private String[] CC = {"","EQ","LT","GT","LE","GE","NE","ANY"};
    private String[] RG = {"","AREG","BREG","CREG"};
    private int LC = -1; // LC denotes current line, and not next

    BufferedReader input;
    BufferedWriter output;
    BufferedWriter symbol_table;
    HashMap<String,Integer> symbols;
    BufferedWriter literal_table;
    HashMap<String,Integer> literals;
    BufferedWriter pool_table;

    Solution(){
        try {
            // Opening input and output files
            input = new BufferedReader(new FileReader("D:\\Avdhoot\\GitHub\\AG1713\\Practicals\\LP1\\Assembler\\Input"));
            output = new BufferedWriter(new FileWriter("D:\\Avdhoot\\GitHub\\AG1713\\Practicals\\LP1\\Assembler\\Intermediate_code"));

            symbol_table = new BufferedWriter(new FileWriter("D:\\Avdhoot\\GitHub\\AG1713\\Practicals\\LP1\\Assembler\\Symbol_table"));
            literal_table = new BufferedWriter(new FileWriter("D:\\Avdhoot\\GitHub\\AG1713\\Practicals\\LP1\\Assembler\\Literal_table"));
            pool_table = new BufferedWriter(new FileWriter("D:\\Avdhoot\\GitHub\\AG1713\\Practicals\\LP1\\Assembler\\Pool_table"));

            symbols = new HashMap<>();
            literals = new HashMap<>();


        } catch (IOException e) {
            System.out.println(e.getMessage());;
        }
    }

    private String[] getClassAndOpcode(String operator){
        String[] ans = new String[2];
        ans[0] = "";
        ans[1] = "";

        // Searching through all arrays
        System.out.println(operator);
        for (int i=0 ; i<IS.length ; i++){
            if (IS[i].equals(operator)){
                ans[0] = "IS";
                ans[1] = String.valueOf(i);
                return ans;
            }
        }
        for (int i=1 ; i<AD.length ; i++){
            if (AD[i].equals(operator)){
                ans[0] = "AD";
                ans[1] = String.valueOf(i);
                return ans;
            }
        }
        for (int i=1 ; i<DL.length ; i++){
            if (IS[i].equals(operator)){
                ans[0] = "DL";
                ans[1] = String.valueOf(i);
                return ans;
            }
        }
        for (int i=1 ; i<CC.length ; i++){
            if (IS[i].equals(operator)){
                ans[0] = "CC";
                ans[1] = String.valueOf(i);
                return ans;
            }
        }
        System.out.println("Not found : " + operator);

        return ans;
    }

    private String[] getRegisterOpcode(String register){
        String[] ans = new String[2];
        ans[0] = "";
        ans[1] = "";

        for (int i=1 ; i<RG.length ; i++){
            if (RG[i].equals(register)){
                ans[0] = "RG";
                ans[1] = String.valueOf(i);
                return ans;
            }
        }

        return ans;
    }

    // ********************************************************************************************************


    public void generateIntermediateCode() throws IOException{
        String card = input.readLine();
        if (!card.startsWith("START")) return; // If it does not start with start
        String[] parts = card.split(" ");
        LC = Integer.parseInt(parts[1]);


        while (!card.equals("END")){
            LC ++;
            card = input.readLine();
            parts = card.split(" ");

            // Getting operators
            String[] classAndOpcode = getClassAndOpcode(parts[0]);
            int operands_begin = 1;
            if (classAndOpcode[0].isEmpty()){
                // Means it is a label

                symbol_table.write(parts[0] + " " + LC);
                symbol_table.newLine();
                symbol_table.flush();
                if (!symbols.containsKey(parts[0])) symbols.put(parts[0],LC);
                else {
                    // BC or DL statements
                }

                classAndOpcode = getClassAndOpcode(parts[1]);
                operands_begin = 1;
            }
            output.write("(" + classAndOpcode[0] + "," + classAndOpcode[1] + ") ");

            // Getting operands
            for (int i=operands_begin ; i< parts.length ; i++){
                String[] operand_details = new String[2];
                operand_details[0] = "";
                operand_details[1] = "";

                if (symbols.containsKey(parts[i])){
                    operand_details[0] = "S";
//                    operand_details[1] = String.valueOf(symbols.);
                } else if (literals.containsKey(parts[i])) {
                    operand_details[0] = "L";
//                    operand_details[1] = String.get
                }

            }






            output.write("(");
            output.newLine();
            output.flush();



        }


    }



}

public class Pass_1 {



    public static void main(String[] args) {
        Solution s = new Solution();
        try {
            s.generateIntermediateCode();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }



}
