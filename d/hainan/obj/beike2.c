// beike2.c

inherit ITEM;

void create()
{
	set_name("��ʱ���", ({ "wucai beike","beike" }) );
	set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("value", 1000);
		set("long", 
"���Ǹ�Ư������ʱ��ǣ�Ӧ�ÿ���������Ǯ��\n");
	}
	setup();
}
