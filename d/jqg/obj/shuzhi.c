// By River 99.5.25
#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
        set_name(GRN"������"NOR, ({ "zao shugan", "shugan"}));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������֦�ɣ���Լһ����ߡ�\n");
                set("value", 1);
                set("material", "wood");
                set("wield_msg", "$N�ó�һ��$n�������С�\n");
                set("unwield_msg", "$N���������е�$n��\n");
        }
        init_hammer(1);
        setup();
}
