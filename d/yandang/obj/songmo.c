
inherit ITEM;

void create()
{
	set_name("��ī", ({ "songmo" , "��ī"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���ڵ���ī,�ɰ�������Ѭ�ƶ���.\n");
	}
}


