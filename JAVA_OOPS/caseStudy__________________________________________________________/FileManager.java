package caseStudy__________________________________________________________;
import java.io.*;


public class FileManager {
    public static void saveReport(CrimeReport report) {
    	String Address = "crimes.txt";
        try (FileWriter writer = new FileWriter(Address, true)) {
            writer.write("🚩. "+report.getClass().getSimpleName() + " at " + report.location + " | Preference: " + report.severity + " | Date: " + report.reportDate + "\n");
            writer.write("—  —  —  —  —  —  —  —  —  —  —  —  —  —  —  —  —  —  —  —  —  —  —  —  —  —  —  —  —  — "+ "\n");

        } catch (IOException e) {
            System.out.println("Error saving report: " + e.getMessage());
        }
    }
}