// tulong-dao.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{

        set_name(HIM"������"NOR, ({ "tulong dao","tulong","dao", "blade" }));
        set_weight(35000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("rigidity", 9);
                set("sharpness", 9);
                set("long", "����һ�ѻ����ڵ������������м�������Ѫ��������������ƥ��
���꽭������Ϊ�˵���ƴ�������һ�ǵ���֮����\n");
                set("value", 1);
                set("unique", 1);
                set("weapon_prop/dodge", -10);
                set("weapon_prop/parry", 5);
                set("material", "steel"); 
                set("wield_neili", 500);
                set("wield_maxneili", 1000);;
                set("wield_str", 25);;
                set("wield_msg", HIM"ֻ���ڹ�һ����$N����������һ�Ѻڳ����Ĵ󵶣����Ǻųơ��������𡱵ı���������\n"NOR);            
                set("unwield_msg", HIM"�ڹ����$nԾ��$N���С�\n"NOR);
                set("treasure",1);
        }
         init_blade(500);
        setup();
}
