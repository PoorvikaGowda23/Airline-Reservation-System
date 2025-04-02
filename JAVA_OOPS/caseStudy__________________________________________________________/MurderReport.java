package caseStudy__________________________________________________________;
import java.util.Date;

public class MurderReport extends CrimeReport {
    public MurderReport(String location, String description, Date reportDate) {
        super(location, description, reportDate);
    }
    
    @Override
    public void generateReport() {
        System.out.println("[Murder Report] Location: " + location + " | Severity: " + severity);
        displayDetails();
    }
}