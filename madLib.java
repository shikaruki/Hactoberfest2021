import java.util.Random;
import java.util.Scanner;

// java program to play Mad Libs game
public class madLib {
    Scanner scanner = new Scanner(System.in);
    String story;
    String name;
    String adjective1;
    String adjective2;
    String noun1;
    String noun2;
    String noun3;
    String adverb;
    String randomNums;
    Random rand = new Random();

    // Getters

    public String getStory() {
        return story;
    }

    public String getName() {
        return name;
    }

    public String getAdjective1() {
        return adjective1;
    }

    public String getAdjective2() {
        return adjective2;
    }

    public String getNoun1() {
        return noun1;
    }

    public String getNoun2() {
        return noun2;
    }

    public String getNoun3() {
        return noun3;
    }

    public String getAdverb() {
        return adverb;
    }

    public String getRandomNums() {
        return randomNums;
    }

    // Setters

    public void setStory(String newStory) {
        this.story = newStory;
    }

    public void setName(String newName) {
        this.name = newName;
    }

    public void setAdjective1(String newAdj1) {
        this.adjective1 = newAdj1;
    }

    public void setAdjective2(String newAdj2) {
        this.adjective2 = newAdj2;
    }

    public void setNoun1(String newNoun1) {
        this.noun1 = newNoun1;
    }

    public void setNoun2(String newNoun2) {
        this.noun2 = newNoun2;
    }

    public void setNoun3(String newNoun3) {
        this.noun3 = newNoun3;
    }

    public void setAdverb(String newAdverb) {
        this.adverb = newAdverb;
    }

    public void setRandomNums() {
        int num = Math.abs(rand.nextInt()) % 100;
        int index = 0;
        int[] numberHolder = new int[3];
        while (index < numberHolder.length) {
            numberHolder[index] = num + index;
            index++;
        }
        randomNums = "not " + numberHolder[0] + " not " + numberHolder[1] + " but " + numberHolder[2];
    }

    // Print instructions to player
    public void printInstructions() {
        System.out.println("Welcome to the MadLibs game. If you type in "
                + "words, we'll give you a story. Start by typing a name");
    }

    // Get data from player
    public void enterNames() {
        setName(scanner.nextLine());
    }

    public void enterNoun1() {
        System.out.println("Give me a noun");
        setNoun1(scanner.nextLine());
    }

    public void enterNoun2() {
        System.out.println("give me another noun");
        setNoun2(scanner.nextLine());
    }

    public void enterNoun3() {
        System.out.println("Give me last noun!!!");
        setNoun3(scanner.nextLine());
    }

    public void enterAdj1() {
        System.out.println("I need an adjective");
        setAdjective1(scanner.nextLine());
    }

    public void enterAdj2() {
        System.out.println("give me another adjective");
        setAdjective2(scanner.nextLine());
    }

    public void enterAdverb() {
        System.out.println("I really need an adverb");
        setAdverb(scanner.nextLine());
    }

    public void putTogetherTheStory() {
        String story;
        int num = Math.abs(rand.nextInt()) % 2;
        if (num == 1) {
            story = "Jesse and her best friend " + getName() + " went to Disney world today! " + "They saw a "
                    + getNoun1() + " in a show at magic kingdom" + " and ate a " + getAdjective1()
                    + " forest for dinner. The next day I" + " ran " + getAdverb() + " to meet Mickey mouse in his "
                    + getNoun2() + " and then that night I gazed at the " + getRandomNums() + " " + getAdjective2()
                    + " fireworks shooting from the " + getNoun3() + " .";
        } else {
            story = "Amanda and her friend " + getName() + " went to the zoo last summer. " + "There they saw a huge "
                    + getNoun1() + " and a tiny little " + getNoun2() + ". That night " + "they decided to climb a "
                    + getAdverb() + " into the " + getNoun3() + " to get a close look. " + "The zoo was "
                    + getAdjective1() + " at night, but they didn't care until... " + getRandomNums() + " "
                    + getAdjective2() + " apes yelled in their faces, making Amanda and " + getName()
                    + " sprint all the way back home.";
        }
        setStory(story);
    }

    public void play() {
        enterNames();
        enterNoun1();
        enterAdj1();
        enterAdj2();
        enterNoun2();
        enterAdverb();
        enterNoun3();
        setRandomNums();
        putTogetherTheStory();
        System.out.println(getStory());
    }

    public static void main(String[] args) {
        madLibs game = new madLibs();
        game.printInstructions();
        game.play();
    }
}
