// /clone/weapon/xuedao.c
// by dubei
#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{

        set_name(RED"�󿳵�"NOR, ({ "kandao","blade","dao" }));
        set_weight(15000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("rigidity", 5);
                set("sharpness", 3);
                set("long", "һ��������嵶������ס�������������һ�㡣������ȥ������ȫ�ǰ���֮ɫ����
Ѫ������,���ǿɲ�.\n");
                set("value", 1000);
                set("unique", 1);

        }
        init_blade(100);
        setup();
}
