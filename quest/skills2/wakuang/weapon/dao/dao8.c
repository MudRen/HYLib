// tulong-dao.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{

        set_name(HIC"������"NOR, ({ "noming dao","noming","dao", "blade" }));
        set_weight(35000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("rigidity", 9);
                set("sharpness", 9);
                set("long", "����һ�ѻ����ڵ���������\n");
                set("value", 3000);
                set("unique", 1);
                set("wield_msg", HIM"ֻ���ڹ�һ����$N����������һ�Ѻڳ����Ĵ󵶣�\n"NOR);            
                set("unwield_msg", HIM"�ڹ����$nԾ��$N���С�\n"NOR);
                set("treasure",1);
        }
         init_blade(300);
        setup();
}
