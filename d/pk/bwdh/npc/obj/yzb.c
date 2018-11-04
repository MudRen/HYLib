// bamboo_stick.c �����
#include <ansi.h>
#include <weapon.h>
inherit STAFF;
inherit F_UNIQUE;

void create()
{
        set_name(GRN"�����"NOR, ({"yuzhu bang", "bang", "stick"}));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�����ŵ����������ȡ�\n");
                set("value", 1000);
                set("rigidity", 7);
                set("material", "bamboo");
                set("weapon_prop/dodge", 3);                
                set("wield_neili", 100);
                set("wield_maxneili", 500);
                set("wield_str", 18);                
                set("skill", ([
                        "name": "stick",
                        "exp_required": 50000,
                        "difficulty": 25,
                             "max_skill": 1,              
                ]) );
                set("wield_msg", "$N���һ�����������������ץ�����С�\n");
                set("unwield_msg", "$N�����е������Ȳ�����С�\n");
               set("treasure",1);
        }
        init_staff(80);
        setup();
}       
