package CaseStudy;

import java.util.*;

public class CrimeReportingSystem {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            System.out.print("💠 Enter username:");
            String username = scanner.nextLine();
            System.out.print("💠 Enter password:");
            String password = scanner.nextLine();
            
            User user = new User(username, "1096");
            if (!user.login(username, password)) {
                throw new InvalidInputException("Invalid credentials!");
            }
            
            System.out.println("💠 Login successful!");
            System.out.println("***************************************");

            System.out.println("💠 Enter an Intger with corresponding crime type ");
            System.out.print("(1- Theft, 2- Harassment, 3- Missing Person, 4- Murder, 5- Cybercrime):");
            int choice = scanner.nextInt();
            scanner.nextLine();
            System.out.println("Describing the Landmarks nearby ");
            System.out.print("💠 Enter location:");
            String location = scanner.nextLine();
            System.out.println("———————————————————————————————————————");
            System.out.println("Describing the Crime scnece with Keywords ");
            System.out.print("💠 Enter description:");
            String description = scanner.nextLine();
            System.out.println("———————————————————————————————————————");

            System.out.println("Input considered in hours only");
            System.out.print("💠 Enter report approximate time (hours ago, or press Enter to consider immediate time):");
            String timeInput = scanner.nextLine();

            System.out.println("———————————————————————————————————————");

            Date reportDate = timeInput.isEmpty() ? new Date() : new Date(System.currentTimeMillis() - (Integer.parseInt(timeInput) * 60 * 60 * 1000));
            
            CrimeReport report;
            switch (choice) {
                case 1:
                    report = new TheftReport(location, description, reportDate);
                    break;
                case 2:
                    report = new HarassmentReport(location, description, reportDate);
                    break;
                case 3:
                    report = new MissingPersonReport(location, description, reportDate);
                    break;
                case 4:
                    report = new MurderReport(location, description, reportDate);
                    break;
                case 5:
                    report = new CyberCrimeReport(location, description, reportDate);
                    break;
               default:throw new InvalidInputException("Invalid choice!");
            }
            report.generateReport();
            System.out.println("———————————————————————————————————————");
            if (report instanceof TheftReport) {
                System.out.println("💠 This is a Theft Report.");
            } else if (report instanceof HarassmentReport) {
                System.out.println("💠 This is a Harassment Report.");
            } else if (report instanceof MissingPersonReport) {
                System.out.println("💠 This is a Missing Person Report.");
            } else if (report instanceof MurderReport) {
                System.out.println("💠 This is a Murder Report.");
            } else if (report instanceof CyberCrimeReport) {
                System.out.println("This is a Cyber Crime Report.");
            }
            report.submitReport();
            report.reviewReport();
            report.archiveReport();
            report.escalateReport();
            report.sendAlert();
            report.logAlert();

            FileManager.saveReport(report);
        } catch (InvalidInputException e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }
}
