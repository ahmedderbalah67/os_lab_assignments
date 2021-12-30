
#include<stdio.h>
#include<malloc.h>
void main()
{


  Summing implements Runnable {

    int y;

     Summing(int y) {
        this.y = y;
    }

     void run() {
        addRondom();
    }

     void addRondom() {
        Random rand = new Random();
        int g = rand.nextInt(10) + 1;
        printif("generated number: " + g);
        synchronized (this) {
            y += g;
        }
    }
}






 static void main(String[] args) {
    int base_num = 0;

    Summing sum2 = new Summing(base);

    Thread x1 = new Thread(sum2);
    Thread x2 = new Thread(sum2);
    Thread x3 = new Thread(sum2);
    Thread x4 = new Thread(sum2);
    Thread x5 = new Thread(sum2);

    x1.start();
    x2.start();
    x3.start();
    x4.start();
    x5.start();

    try {
        x1.join();
        x2.join();
        x3.join();
        x4.join();
        x5.join();
    } catch (InterruptedException e) {
        e.printStackTrace();
    }

    System.out.print(" result: " + sum2.y);
}