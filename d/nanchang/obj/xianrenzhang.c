
inherit ITEM;

void create()
{
        set_name("������", ({ "xianren zhang","zhang" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long","����һ�������ƣ���������������ҩ�\n");
                set("medicine_type",([
			    "gongxiao" :20+random(10),
                            "type" : "��Ѫ",
		]));
                
        }

      
        setup();
}
