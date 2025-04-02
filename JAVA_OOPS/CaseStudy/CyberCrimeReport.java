package CaseStudy;
import java.util.Date;

public class CyberCrimeReport extends CrimeReport {
    public CyberCrimeReport(String location, String description, Date reportDate) {
        super(location, description, reportDate);
    }
    
    @Override
    public void generateReport() {
        System.out.println("[Cyber Crime Report] Location: " + location + " | Severity: " + severity);
        displayDetails();
    }
}
