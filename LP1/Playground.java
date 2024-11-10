import java.util.*;

class Assembler1 {

    ArrayList<ArrayList<String>> ic = null;
    ArrayList<ArrayList<String>> sym = null;
    ArrayList<ArrayList<String>> lit = null;
    ArrayList<ArrayList<String>> pol = null;

    public String[][] assignLC(String[][] asm) {
        int start_value = 0;
        for (int i = 0; i < asm.length; i++) {
            for (int j = 0; j < 4; j++) {
                if (asm[i][j].equals("START")) {
                    start_value = Integer.parseInt(asm[i][j + 1]);
                }
            }
            if (i > 0) {
                start_value += 1;
            }
            asm[i][0] = String.valueOf(start_value);
        }
        return asm;
    }

    public void printCode(String[][] asm) {
        for (String[] strings : asm) {
            for (String string : strings) {
                System.out.print("\t" + string);
            }
            System.out.println();
        }
    }

    public void generateOutput(String[][] asm, String[][] mot) {
        ic = new ArrayList<>();
        sym = new ArrayList<>();
        lit = new ArrayList<>();
        pol = new ArrayList<>();

        int sym_index = 0;
        int lit_index = 0;
        int pool_start_index = 0;

        for (int i = 0; i < asm.length; i++) {
            ic.add(new ArrayList<>());

            for (int j = 0; j < 4; j++) {
                String token = asm[i][j];
                boolean isFound = false;

                for (String[] motEntry : mot) {
                    if (token.equals(motEntry[0])) {
                        String icStr = "(" + motEntry[1] + "," + motEntry[2] + ")";
                        ic.get(i).add(icStr);
                        isFound = true;
                        break;
                    }
                }

                if (!isFound && token.matches("[a-zA-Z]+")) {
                    boolean symbolExists = false;
                    for (ArrayList<String> symEntry : sym) {
                        if (symEntry.get(1).equals(token)) {
                            symbolExists = true;
                            break;
                        }
                    }
                    if (!symbolExists) {
                        ArrayList<String> symEntry = new ArrayList<>();
                        symEntry.add(String.valueOf(sym_index++));
                        symEntry.add(token);
                        symEntry.add(asm[i][0]);
                        sym.add(symEntry);
                    }
                    ic.get(i).add("(S," + token + ")");
                }

                if (token.matches("[0-9]+") && !token.equals(asm[i][0])) {
                    ArrayList<String> litEntry = new ArrayList<>();
                    litEntry.add(String.valueOf(lit_index++));
                    litEntry.add(token);
                    litEntry.add(asm[i][0]);
                    lit.add(litEntry);
                    ic.get(i).add("(L," + token + ")");
                }
            }

            // Handle POOLTAB management with LTORG or END
            if (asm[i][2].equals("LTORG") || asm[i][2].equals("END")) {
                ArrayList<String> poolEntry = new ArrayList<>();
                poolEntry.add(String.valueOf(pool_start_index));
                pol.add(poolEntry);
                pool_start_index = lit_index; // Update to the new starting literal index
            }
        }
    }
}

public class Playground {
    public static void main(String[] args) {

        String asm_code[][] = {
                {"", "", "START", "200", ""},
                {"", "", "MOVER", "AREG", "X"},
                {"", "", "MOVEM", "BREG", "Y"},
                {"", "X", "DS", "1", ""},
                {"", "", "END", "", ""}
        };

        String mot[][] = {
                {"STOP", "IS", "00"},
                {"ADD", "IS", "01"},
                {"SUB", "IS", "02"},
                {"MULT", "IS", "03"},
                {"MOVER", "IS", "04"},
                {"MOVEM", "IS", "05"},
                {"COMP", "IS", "06"},
                {"BC", "IS", "07"},
                {"DIV", "IS", "08"},
                {"READ", "IS", "09"},
                {"PRINT", "IS", "10"},
                {"START", "AD", "01"},
                {"END", "AD", "02"},
                {"ORIGIN", "AD", "03"},
                {"EQU", "AD", "04"},
                {"LTORG", "AD", "05"},
                {"DS", "DL", "01"},
                {"DC", "DL", "02"},
                {"AREG", "RG", "01"},
                {"BREG", "RG", "02"},
                {"CREG", "RG", "03"},
        };

        Assembler1 assembler = new Assembler1();
        String[][] asm_with_lc = assembler.assignLC(asm_code);
        assembler.printCode(asm_with_lc);
        assembler.generateOutput(asm_with_lc, mot);

        System.out.println("Intermediate Code (IC)");
        for (ArrayList<String> icLine : assembler.ic) {
            for (String icEntry : icLine) {
                System.out.print(icEntry + "\t");
            }
            System.out.println();
        }

        System.out.println("Symbol Table (SYM)");
        for (ArrayList<String> symEntry : assembler.sym) {
            for (String symField : symEntry) {
                System.out.print(symField + "\t");
            }
            System.out.println();
        }

        System.out.println("Literal Table (LIT)");
        for (ArrayList<String> litEntry : assembler.lit) {
            for (String litField : litEntry) {
                System.out.print(litField + "\t");
            }
            System.out.println();
        }

        System.out.println("Pool Table (POOL)");
        for (ArrayList<String> poolEntry : assembler.pol) {
            for (String poolField : poolEntry) {
                System.out.print(poolField + "\t");
            }
            System.out.println();
        }
    }
}
