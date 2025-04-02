package caseStudy__________________________________________________________;
import java.util.Date;

public class TheftReport extends CrimeReport {
    public TheftReport(String location, String description, Date reportDate) {
        super(location, description, reportDate);
    }
    
    @Override
    public void generateReport() {
        System.out.println("[Theft Report] Location: " + location + " | Severity: " + severity);
        displayDetails();
    }
}
