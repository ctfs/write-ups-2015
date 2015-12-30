#include "somelib.hxx"
#include <iostream>
#include <cstdlib>

void error()
{
    std::cout << "Wrong password" << std::endl;
    std::exit(-1);
}

int pow(int x, int n)
{
    int ret(1);
    for (int i = 1; i <= n; ++i)
        ret *= x;
    return ret;
}

void check_password(std::string& p)
{
    if (p.size() != 13)
    {
        std::cout << "Password must be 13 characters" << std::endl;
        std::exit(-1);
    }

    if (p[0]+p[1] != pow(I-----I,2) * pow(I-----------I,2) + (I---I)) error();

    if (p[1]+p[2] != pow(I-------I,2) * pow(I-----I,4) - (I---I)) error();

    if (p[0]*p[2] != (pow(pow(I-------I,2) * pow(I-----I,3) - (I---I),2) - (I-----I)*(I-------I))) error();

    if (p[3]+p[5] != pow((o-------o
                          |       !
                          !       !
                          !       !
                          o-------o).A,2) * (I-----I)+(I---I)) error();

    if (p[3]+p[4] != pow((o-----------o
                          |           !
                          !           !
                          !           !
                          o-----------o).A,2)+(I---I)) error();

    if (p[4]*p[5] != (pow((o-------------o
                           |             !
                           !             !
                           !             !
                           o-------------o).A,2)-(I---I))*(I-----I)*pow(I-------I,2)) error();

    if (p[7]+p[8] != (o-----------o
                      |L           \
                      | L           \
                      |  L           \
                      |   o-----------o|!
                      o   |           !
                       L  |           !
                        L |           !
                         L|           !
                          o-----------o).V*pow(I-----I,2) - pow((o-------o
                                                                      |       !
                                                                      !       !
                                                                      o-------o).A,2) + (I---I)) error();

    if (p[6]+p[8] != (o-----------o
                      |L           \
                      | L           \
                      |  L           \
                      |   L           \
                      |    L           \
                      |     o-----------o
                      |     !           !
                      o     |           !
                       L    |           !
                        L   |           !
                         L  |           !
                          L |           !
                           L|           !
                            o-----------o).V - (I-----I)) error();

    if (p[6]*p[7] != (o---------------------o
                      |L                     \
                      | L                     \
                      |  L                     \
                      |   L                     \
                      |    L                     \
                      |     L                     \
                      |      L                     \
                      |       L                     \
                      |        o---------------------o
                      |        !                     !
                      !        !                     !
                      o        |                     !
                       L       |                     !
                        L      |                     !
                         L     |                     !
                          L    |                     !
                           L   |                     !
                            L  |                     !
                             L |                     !
                              L|                     !
                               o---------------------o).V*(pow(I-------I,2) + (I-----I)) + pow(I-----I,6)) error();

    if (p[9]+p[10]*p[11] != (o---------o
                             |L         \
                             | L         \
                             |  L         \
                             |   L         \
                             |    o---------o
                             |    !         !
                             !    !         !
                             o    |         !
                              L   |         !
                               L  |         !
                                L |         !
                                 L|         !
                                  o---------o).V*(I-------I)*pow(I-----I,4)-(I---I)) error();

    if (p[10]+p[9]*p[11] != (o-----------o
                             |L           \
                             | L           \
                             |  L           \
                             |   L           \
                             |    L           \
                             |     o-----------o
                             |     !           !
                             o     |           !
                              L    |           !
                               L   |           !
                                L  |           !
                                 L |           !
                                  L|           !
                                   o-----------o).V*pow(I-------I,3) - (I-----------I)*((I-----I)*(I-----------I)+(I---I))) error();

    if (p[9]+p[10] != (o-------------o
                       |L             \
                       | L             \
                       |  L             \
                       |   L             \
                       |    L             \
                       |     o-------------o
                       |     !             !
                       o     |             !
                        L    |             !
                         L   |             !
                          L  |             !
                           L |             !
                            L|             !
                             o-------------o).V-(I-----------I)) error();

    if (p[12] != 'w') error();
}

int main()
{
    std::cout << "Guess passwd" << std::endl;
    std::string password;
    std::cin >> password;
    check_password(password);
    std::cout << "Correct password! It's your flag, bruh" << std::endl;
}
