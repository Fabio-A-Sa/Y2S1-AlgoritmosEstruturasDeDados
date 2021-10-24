#include "Mail.cpp"
#include "PostOffice.cpp"
#include "Postman.cpp"
#include <string>
#include <iostream>
using namespace std;

int main () {

    cout << endl << "Preços (1 Correcto, 0 Incorrecto): " << endl;
    RegularMail m1("manuel", "ana","3330-454", 401); cout << (m1.getPrice() == 140) << endl;
    RegularMail m2("ana", "rui","4400-146", 10); cout << (m2.getPrice() == 50) << endl;
    GreenMail m3("maria", "luis","2520-110", "envelope"); cout << (m3.getPrice() == 80) << endl;
    GreenMail m4("carla", "lara","7100-514", "box"); cout << (m4.getPrice() == 240) << endl;

    cout << endl << "Mail for Postman (1 Correcto, 0 Incorrecto): " << endl;
    PostOffice po;
    Postman p1;
    p1.setName("joao");
    p1.addMail(new RegularMail("ana", "rui","4400-146", 33));
    Postman p2;
    p2.setName("paulo");
    p2.addMail(new RegularMail("rui", "ana","3330-454", 33));
    p2.addMail(new RegularMail("luis", "maria","8600-306", 67));
    p2.addMail(new RegularMail("carla", "lara","7100-514", 67));
    p2.addMail(new RegularMail("luis", "rui","4400-146", 33));
    Postman p3;
    p3.setName("fernando");
    p3.addMail(new RegularMail("manuel", "ana","3330-454", 33));
    po.addPostman(p1);
    po.addPostman(p2);
    po.addPostman(p3);
    vector <Mail *> mailP = po.removePostman("joao");
    cout << (mailP.size() == 1) << endl;
    cout << (po.getPostman().size() == 2) << endl;
    mailP.clear();
    mailP = po.removePostman("sergio");
    cout << (mailP.size() == 0) << endl;
    mailP.clear();
    mailP = po.removePostman("paulo");
    cout << (mailP.size() == 4) << endl;
    mailP.clear();
    mailP = po.removePostman("fernando");
    cout << (mailP.size() == 1) << endl;
    cout << (po.getPostman().size() == 0) << endl;

    cout << endl << "End of the day (1 Correcto, 0 Incorrecto): " << endl;
    PostOffice poo("2600-000", "3999-999");
    poo.addMailToSend(new RegularMail("manuel", "ana","3330-454", 401));
    poo.addMailToSend(new RegularMail("ana", "rui","4400-146", 10));
    poo.addMailToSend(new GreenMail("maria", "luis","2520-110", "envelope"));
    poo.addMailToSend(new GreenMail("carla", "lara","7100-514", "box"));
    unsigned int bal = 0;
    vector<Mail *> mailToOtherPO = poo.endOfDay(bal);
    cout << (bal == 510) << endl;
    cout << (mailToOtherPO.size() == 3) << endl;
    cout << (poo.getMailToDeliver().size() == 1) << endl;
    cout << (poo.getMailToSend().size() == 0) << endl;
    PostOffice po2("2600-000", "3999-999");
    po2.addMailToSend(new RegularMail("rita", "joana","3200-514", 120));
    mailToOtherPO = po2.endOfDay(bal);
    cout << (bal == 140) << endl;
    cout << (mailToOtherPO.size() == 0) << endl;
    cout << (po2.getMailToDeliver().size() == 1) << endl;
    cout << (po2.getMailToSend().size() == 0) << endl;

    return 0;
}

/*

TEST(test_1, addMailToPostman){
    PostOffice po;
    Postman p1;
    p1. setName("joao");
    p1.addMail(new RegularMail("ana", "rui","4400-146", 33));
    p1.addMail(new RegularMail("luis", "rui","4400-146", 33));
    Postman p2;
    p2. setName("paulo");
    Postman p3;
    p3.setName("fernando");
    p3.addMail(new RegularMail("manuel", "ana","3330-454", 33));
    po.addPostman(p1);
    po.addPostman(p2);
    po.addPostman(p3);

    Postman px = po.addMailToPostman(new RegularMail("rui", "ana","3330-454", 33),"paulo");
    EXPECT_EQ(1,px.getMail().size());

    EXPECT_THROW(po.addMailToPostman(new RegularMail("rui", "ana","3330-454", 33),"luis"), NoPostmanException);

    try {
        px = po.addMailToPostman(new RegularMail("rui", "ana","3330-454", 33),"joao");
        EXPECT_EQ(3,px.getMail().size());
        px = po.addMailToPostman(new RegularMail("rui", "ana","3330-454", 33),"ricardo");
    }
        catch(NoPostmanException &e) {
        EXPECT_EQ("ricardo", e.getName());
    }

    px = po.addMailToPostman(new RegularMail("rui", "ana","3330-454", 33),"fernando");
    EXPECT_EQ(2,px.getMail().size());
}

/*/
