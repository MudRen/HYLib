// jinling-suo.c ������
// By Kayin @ CuteRabbit Studio 1999/3/21 new
#include <ansi.h> 
#include <weapon.h>
inherit WHIP;

void create()
{
        set_name(HIY"����"HIW"��"NOR, ({ "jinling suo", "suo" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����׵�˿��ϵ�ɵĽ�������˿��������������С���壬���Ƿ�������������\n");
                set("value", 100000);
                 set("no_drop", "�������������뿪�㡣\n");
                set("no_give", "�����������ܸ��ˡ�\n");
                set("treasure",1);
                set("nopawn",1);
            set("no_get",1);
               set("material", "gold");
                set("wield_msg", HIC"$N�ӻ����ͳ�һ��$n�������С�\n"NOR);
                set("unwield_msg", HIC"$N�����е�$n���뻳�С�\n"NOR);
	        set("armor_prop/attack", 100);

        }
        init_whip(400);
        setup();
}

