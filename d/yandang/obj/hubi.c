
inherit ITEM;

void create()
{
	set_name("����", ({ "hubi" , "����"}) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
		set("long", "һ֧մ���˺�ī�ı�\n");
	}
}


