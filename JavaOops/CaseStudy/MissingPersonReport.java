package CaseStudy;
import java.util.Date;

public class MissingPersonReport extends CrimeReport {
    public MissingPersonReport(String location, String description, Date reportDate) {
        super(location, description, reportDate);
    }
    
    @Override
    public void generateReport() {
        System.out.println("[Missing Person Report] Location: " + location + " | Severity: " + severity);
        displayDetails();
    }
}