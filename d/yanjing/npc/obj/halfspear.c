#include <weapon.h>

inherit CLUB;

void create()
{
set_name("�����ǹ",({"iron spear","qiang","spear"}));
set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
set("long","����ǹֻʣ�°��,ǹ����˸�[��]��.\n");
set("value",600);
                set("material", "iron");
set("wield_msg","$N�ó�һ��$n,���������˸�ǹ��!\n");;
                set("unwield_msg", "$N�������е�$n��\n");
        }

init_club(40);
        setup();
}

