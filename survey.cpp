#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int countRepub(int questionNumber, char answers) {
    // Open the file with the provided path for appending
    ifstream republicanFile("republicans.txt");

    // Check if the file is opened successfully
    if (!republicanFile.is_open()) {
        cerr << "Failed to open the file for writing: " << endl;
        return 1; // Exit the function
    }

    //search the file
    string line;
    int rcount = 0;
    string currentQuestionIdentifier = "Question " + to_string(questionNumber) + ": ";
    while (getline(republicanFile, line)) {
        if (line.find(currentQuestionIdentifier) != string::npos){
            for (char c : line){
                if (c == answers){
                    ++rcount;
                }
            }
        }
    }

    republicanFile.close();

    return rcount;
    
}

int countDem(int questionNumber, char answers) {
    // Open the file with the provided path for appending
    ifstream democratFile("democrats.txt");

    // Check if the file is opened successfully
    if (!democratFile.is_open()) {
        cerr << "Failed to open the file for writing: " << endl;
        return 1; // Exit the function
    }

    //search the file
    string line;
    int dcount = 0;
    string currentQuestionIdentifier = "Question " + to_string(questionNumber) + ": ";
    while (getline(democratFile, line)) {
        if (line.find(currentQuestionIdentifier) != string::npos){
            for (char c : line){
                if (c == answers){
                    ++dcount;
                }
            }
        }
    }

    democratFile.close();

    return dcount;

}

int countGreen(int questionNumber, char answers) {
    // Open the file with the provided path for appending
    ifstream greenFile("green.txt");

    // Check if the file is opened successfully
    if (!greenFile.is_open()) {
        std::cerr << "Failed to open the file for writing: " << endl;
        return 1; // Exit the function
    }

    //search the file
    string line;
    int gcount = 0;
    string currentQuestionIdentifier = "Question " + to_string(questionNumber) + ": ";
    while (getline(greenFile, line)) {
        if (line.find(currentQuestionIdentifier) != string::npos){
            for (char c : line){
                if (c == answers){
                    ++gcount;
                }
            }
        }
    }

    greenFile.close();

    return gcount;

}

int countLib(int questionNumber, char answers) {
    // Open the file with the provided path for appending
    ifstream libertarianFile("libertarians.txt");

    // Check if the file is opened successfully
    if (!libertarianFile.is_open()) {
        std::cerr << "Failed to open the file for writing: " << endl;
        return 1; // Exit the function
    }

    //search the file
    string line;
    int lcount = 0;
    string currentQuestionIdentifier = "Question " + to_string(questionNumber) + ": ";
    while (getline(libertarianFile, line)) {
        if (line.find(currentQuestionIdentifier) != string::npos){
            for (char c : line){
                if (c == answers){
                    ++lcount;
                }
            }
        }
    }

    libertarianFile.close();

    return lcount;

}

void write(ofstream& file, const string& path, const char answers[]) {
    // Open the file with the provided path for appending
    file.open(path);

    // Check if the file is opened successfully
    if (!file.is_open()) {
        std::cerr << "Failed to open the file for writing: " << path << endl;
        return; // Exit the function
    }

    // Write answers to the file
    for (int i = 0; i < 20; ++i) {
        file << "Question " << (i + 1) << ": " << answers[i] << endl;
    }

    // Close the file
    file.close();
}

//Bayes Theory
double calculate(double answer, double prior){
    double margin = (answer * prior) + ((1 - answer) * (1 - prior));
    double posterior = answer * prior / margin;
    return posterior;
}


bool isFileEmpty(const vector<string>& filenames) {
    for (const string& filename : filenames) {
        ifstream file(filename);
        if (file.peek() == ifstream::traits_type::eof()) {
            // File is empty
            file.close();
            return true; // Return true if any file is empty
        }
        file.close();
    }
    // No file is empty
    return false;
}

int main() {
    //Creates the Political Files
    ofstream republican("republican.txt");
    republican.close();
    ofstream democrat("democrat.txt");
    democrat.close();
    ofstream green("green.txt");
    green.close();
    ofstream libertarian("libertarian.txt");
    libertarian.close();

    //Array of 20 questions being asked to the user. The Answer format would be A=republican, B=democrat, C=green, D=libertarian
    string question[20][5] = {
        {"What is your stance on gun control laws?", "A. Support Second Amendment rights and oppose strict gun control measures.", "B. Advocate for stricter gun control measures, including background checks and bans on assault weapons.", "C. Support strict gun control measures, including bans on assault weapons and high-capacity magazines.", "D. Advocate for the right to own and carry firearms with minimal government regulation."},
        {"How do you propose to address climate change and promote environmental sustainability?", "A. Focus on economic growth and innovation to address environmental challenges without burdensome regulations.", "B. Support government regulations and investments in renewable energy to combat climate change.", "C. Advocate for strong environmental regulations and prioritize sustainability over economic growth.", "D. Believe that free markets and property rights can address environmental issues more effectively than government intervention."},
        {"What measures would you implement to promote economic growth and job creation?", "A. Advocate for lower taxes, deregulation, and free market principles to stimulate economic growth.", "B. Support investments in infrastructure, education, and healthcare to create jobs and reduce income inequality.", "C. Promote sustainable economic practices and prioritize job creation in green industries.", "D. Advocate for minimal government intervention in the economy and support free trade agreements."},
        {"What is your approach to healthcare reform?", "A. Support market-based solutions and oppose government-run healthcare programs.", "B. Advocate for universal healthcare coverage and expand government involvement in healthcare delivery.", "C. Support a single-payer healthcare system that provides comprehensive coverage for all citizens.", "D. Believe in a free-market approach to healthcare and advocate for deregulation to increase competition."},
        {"How do you plan to address racial inequality and promote social justice?", "A. Emphasize individual responsibility and oppose affirmative action and identity politics.", "B. Support policies to address systemic racism and promote equal opportunities for all individuals.", "C. Advocate for reparations for historical injustices and support affirmative action policies.", "D. Believe in equal treatment under the law and oppose government intervention in social issues."},
        {"What is your stance on immigration policy?", "A. Advocate for stricter border security and enforcement of immigration laws to protect national security.", "B. Support comprehensive immigration reform, including a pathway to citizenship for undocumented immigrants.", "C. Advocate for open borders and the rights of immigrants, refugees, and asylum seekers.", "D. Support free movement of people and oppose government restrictions on immigration."},
        {"How would you address the national debt and fiscal responsibility?", "A. Advocate for spending cuts, entitlement reforms, and balanced budgets to reduce the national debt.", "B. Support a combination of spending cuts and tax increases to address the national debt.", "C. Advocate for progressive taxation and investments in social programs to reduce income inequality.", "D. Support reducing government spending and eliminating deficits through fiscal discipline."},
        {"What is your foreign policy approach?", "A. Advocate for a strong military and assertive foreign policy to protect national interests and security.", "B. Support diplomacy, multilateralism, and international cooperation to address global challenges.", "C. Advocate for non-interventionism and prioritize diplomacy over military intervention.", "D. Support a non-interventionist foreign policy and oppose military intervention unless in self-defense."},
        {"How do you propose to reform the criminal justice system?", "A. Support tough-on-crime policies, including mandatory minimum sentences and expanded law enforcement powers.", "B. Advocate for criminal justice reform, including ending mass incarceration and addressing systemic racism.", "C. Support restorative justice and community-based alternatives to incarceration.", "D. Advocate for decriminalization of non-violent offenses and reducing the role of government in policing."},
        {"What is your stance on government surveillance and privacy rights?", "A. Support government surveillance programs to combat terrorism and protect national security.", "B. Advocate for privacy rights and restrictions on government surveillance to protect civil liberties.", "C. Oppose government surveillance and support strict limits on data collection and retention.", "D. Advocate for privacy rights and oppose government intrusion into personal data and communications."},
        {"What is your stance on taxation and fiscal policy?", "A. Advocate for lower taxes, especially for businesses and high-income earners, to stimulate economic growth.", "B. Support progressive taxation and raising taxes on the wealthy to fund social programs and reduce income inequality.", "C. Advocate for higher taxes on corporations and the wealthy to fund social programs and address climate change.", "D. Support minimal taxation and advocate for a flat tax or consumption-based tax system."},
        {"How do you plan to address education reform and improve the quality of public schools?", "A. Support school choice initiatives, including vouchers and charter schools, to increase competition and parental involvement.", "B. Advocate for increased funding for public education, teacher pay raises, and investments in early childhood education.", "C. Support community-driven education reforms and oppose standardized testing and privatization of schools.", "D. Advocate for decentralization of education and parental control over schooling choices, including homeschooling and private schools."},
        {"What measures would you implement to address income inequality and support working-class families?", "A. Support deregulation, free market principles, and job creation to increase economic opportunities for all.", "B. Advocate for raising the minimum wage, strengthening labor unions, and implementing progressive economic policies.", "C. Support universal basic income, wealth redistribution, and guaranteeing a living wage for all workers.", "D. Advocate for reducing government intervention in the economy and promoting entrepreneurship and innovation."},
        {"What is your approach to foreign aid and international development?", "A. Support targeted foreign aid to strategic allies and countries that align with U.S. interests, with a focus on economic development and security assistance.", "B. Advocate for humanitarian aid, poverty alleviation, and promoting democracy and human rights through foreign assistance.", "C. Support debt relief, fair trade agreements, and sustainable development initiatives to address global poverty and inequality.", "D. Oppose foreign aid and military intervention abroad, and advocate for voluntary cooperation and non-interventionist policies."},
        {"How would you address healthcare affordability and access to quality care?", "A. Support market-based solutions, competition among healthcare providers, and reducing government involvement in healthcare.", "B. Advocate for expanding access to healthcare through government programs such as Medicaid and the Affordable Care Act.", "C. Support a single-payer healthcare system that provides universal coverage and eliminates private insurance.", "D. Advocate for deregulation of the healthcare industry and promoting health savings accounts and consumer-driven healthcare."},
        {"What measures would you implement to address gender equality and reproductive rights?", "A. Support equal pay for equal work and oppose government intervention in private sector employment practices.", "B. Advocate for policies to close the gender pay gap, protect reproductive rights, and combat gender-based violence and discrimination.", "C. Support reproductive justice, access to comprehensive reproductive healthcare, and ensuring equal rights for all genders.", "D. Advocate for individual liberty and oppose government involvement in personal decisions, including reproductive choices."},
        {"What is your stance on trade policy and international trade agreements?", "A. Advocate for free trade agreements that reduce barriers to trade and promote economic growth and global competitiveness.", "B. Support fair trade policies that protect workers' rights, environmental standards, and domestic industries from unfair competition.", "C. Oppose corporate-dominated trade agreements and advocate for fair trade policies that prioritize people and the planet over profits.", "D. Advocate for unrestricted free trade and oppose government tariffs, subsidies, and trade restrictions."},
        {"How would you address housing affordability and homelessness?", "A. Support reducing government regulations and zoning restrictions to increase housing supply and affordability.", "B. Advocate for increasing funding for affordable housing programs, rent control measures, and homelessness prevention initiatives.", "C. Support policies to provide affordable housing for all, including rent control, public housing development, and tenant protections.", "D. Advocate for reducing government involvement in the housing market and promoting property rights and voluntary solutions to homelessness."},
        {"What is your approach to national security and counterterrorism efforts?", "A. Advocate for a strong military, robust intelligence capabilities, and aggressive counterterrorism measures to protect national security.", "B. Support diplomacy, multilateral cooperation, and targeted military interventions to address global security threats.", "C. Oppose militarism and imperialism, advocate for nonviolent conflict resolution, and address root causes of terrorism through diplomacy and aid.", "D. Advocate for non-interventionism, reducing the military budget, and prioritizing defense over offense in national security strategy."},
        {"What Political Party are you afiliated with?", "A. Republican", "B. Democrat", "C. Green", "D. Libertarian"},
    };

    char answers[20];

    //allowing bayes theory to used .25 for the first calculations
    double rprior = 0.25;
    double dprior = 0.25;
    double gprior = 0.25;
    double lprior = 0.25;
    for (int i = 0; i < 20; ++i) {
        //prompt user with questions
        cout << "Question: " << question[i][0] << endl;
        cout << question[i][1] << endl;
        cout << question[i][2] << endl;
        cout << question[i][3] << endl;
        cout << question[i][4] << endl;

        //store answers in a array
        cout << "Answer(A/B/C/D): ";
        cin >> answers[i];
        cout << endl;

        //Checks if the files are empty therefore starting the guessing funciton.
        vector<string> filenames = {"republicans.txt", "democrats.txt", "green.txt", "libertarians.txt"};
        if (isFileEmpty(filenames)){
            continue;
        } else {
            //counting the user answers
            double repub = countRepub(i + 1, answers[i]);
            double dem = countDem(i + 1, answers[i]);
            double green = countGreen(i + 1, answers[i]);
            double lib = countLib(i + 1, answers[i]);

            double total = repub + dem + green + lib;

            double rAnswer = repub/total;
            double dAnswer = dem/total;
            double gAnswer = green/total;
            double lAnswer = lib/total;

            //calculating Bayes Theory
            double r = calculate(rAnswer, rprior);
            double d = calculate(dAnswer, dprior);
            double g = calculate(gAnswer, gprior);
            double l = calculate(lAnswer, lprior);

            //if the algorithm sees that the user is 75% affiliated with one of the policital parties, it will print it out.
            if (r >= 0.75)
            cout << "You are Republican" << endl;
            if (d >= 0.75)
            cout << "You are Democrat" << endl;
            if (g >= 0.75)
            cout << "You are Green" << endl;
            if (l >= 0.75)
            cout << "You are Libertarian" << endl;

            //allows the next calculations to use the updated probability
            rprior = r;
            dprior = d;
            gprior = g;
            lprior = l;

        }

    }

    //Write all the answers to the coresponding files
    switch (answers[19]) {
        case 'A':
            write(republican, "republican.txt", answers);
            break;
        case 'B':
            write(democrat, "democrat.txt", answers);
            break;
        case 'C':
            write(green, "green.txt", answers);
            break;
        default:
            write(libertarian, "libertarian.txt", answers);
    }

    return 0;
}
