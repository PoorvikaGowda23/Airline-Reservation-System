package CrimeReportSystem;

import java.util.Date;

abstract class CrimeReport implements Reportable ,Alertable{
    protected String location;
    protected String description;
    protected String severity;
    protected Date reportDate;
    
    public CrimeReport(String location, String description, Date reportDate) {
        this.location = location;
        this.description = description;
        this.reportDate = reportDate;
        this.severity = determineSeverity();
    }
    
    public abstract void generateReport();
    
    public void displayDetails() {
        System.out.println("→ Report Date: " + reportDate);
        System.out.println("→ Location: " + location);
        System.out.println("→ Description: " + description);
        System.out.println("→ Severity: " + severity);
    }
    
    private String determineSeverity() {
        Date currentTime = new Date();
        long diffInMillis = currentTime.getTime() - reportDate.getTime();
        long diffInHours = diffInMillis / (1000 * 60 * 60);
        
        if (diffInHours > 3) {
            return "Highest";
        } else if (diffInHours >= 2) {
            return "High";
        } else if (diffInHours > 0) {
            return "Medium";
        } else {
            return "Low";
        }
    }
    
    @Override
    public void submitReport() {
        System.out.println("💠 Report submitted successfully.");
    }
    
    @Override
    public void reviewReport() {
        System.out.println("💠 Report under review.");
    }
    
    @Override
    public void archiveReport() {
        System.out.println("💠 Report has been archived.");
    }
    
    @Override
    public void escalateReport() {
        System.out.println("💠 Report has been escalated to higher authorities.");
    }
    @Override
    public void sendAlert() {
        System.out.println("💠 Alert sent to authorities.");
    }
    
    @Override
    public void logAlert() {
        System.out.println("💠 Alert logged in the system.");
    }
    

}