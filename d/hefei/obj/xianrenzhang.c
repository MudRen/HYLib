
inherit ITEM;

void create()
{
        set_name("������", ({ "xianren zhang","zhang" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
				set("long","����һ�������ƣ��������������ơ�\n");
                set("value", 200);
				set("heal",([
					"heals":15,
					]));
                
        }

      
        setup();
}
