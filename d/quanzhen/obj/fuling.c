//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIG"����"NOR, ({"fuling"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "Ǯ");
                set("long","���ߣ��ݱ�ֲ�����Ѫ�������࣬�ǲ��ɶ�õ��ϼ�ҩ�ġ�\n");
                set("value", 10000);
				set("yaocai", 1);
        		set("cure_s",40);
		        set("cure_d",0);
		        set("cure_n",53);
		
        }
        setup();
}
