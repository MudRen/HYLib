//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIY"������"NOR, ({"heshouwu","shouwu"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "֧");
                set("long","�����ڣ��ݱ�ֲ��������ҩ����������֮�･�����Σ����̲���Ʒ��\n");
                set("value", 6000);
				set("yaocai", 1);
        		set("cure_s",80);
		        set("cure_d",0);
		        set("cure_n",10);
		
        }
        setup();
}
