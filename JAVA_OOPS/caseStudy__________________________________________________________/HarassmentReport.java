package caseStudy__________________________________________________________;
import java.util.Date;

public class HarassmentReport extends CrimeReport {
    public HarassmentReport(String location, String description, Date reportDate) {
        super(location, description, reportDate);
    }
    
    @Override
    public void generateReport() {
        System.out.println("[Harassment Report] Location: " + location + " | Severity: " + severity);
        displayDetails();
    }
}
