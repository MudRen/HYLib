inherit ITEM;

void create()
{
	set_name("ҩʦ������", ({ "shenxiang" , "xiang"}) );
	set_weight(500000);
	set("no_get",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��ʯ��ҩʦ����.\n");
		set("value", 1);
             set("no_drop",1);
		set("material", "stone");
	}
setup();
}
