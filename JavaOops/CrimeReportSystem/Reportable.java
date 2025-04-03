package CrimeReportSystem;

public interface Reportable {
    void submitReport();
    void reviewReport();
    void archiveReport();
    void escalateReport();
}