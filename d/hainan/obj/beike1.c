// beike1.c

inherit ITEM;

void create()
{
	set_name("����", ({ "beike" }) );
	set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("value", 200);
		set("long", 
"���Ǹ�Ư���ı��ǣ�\n");
	}
	setup();
}
