// mubei Ĺ��

#include <weapon.h>
inherit HAMMER;

void create()
{
        set_name("Ĺ��", ({ "mu bei","bei" }) );
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����д���ǡ��ȿ��Ƹ����ϱ�֮Ĺ����\n");
                set("material", "stone");
                set("wield_msg", "$N���ŵ���һ���ؿ��˸�ͷ��˵���Բ��𣬰���һ��Ĺ����\n");
                set("unwield_msg", "$N��Ĺ��������һ�ţ���С���ҵ��Լ��Ľš�\n");
        }
        init_hammer(30);
        setup();
}

