inherit ITEM;

void create()
{
	set_name("��Ʒ", ({ "gong pin" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�й�Ʒ��\n");
//		set("no_drop","��Ҫ�Ҷ����ⶫ������ʹ��\n");
		set("no_get",1);
    	        set("no_steal",1);
		set("no_put",1);
                set("yuer",1);	
		set("unit", "��");
		set("value", 0);
	}
}
