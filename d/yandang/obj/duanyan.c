
inherit ITEM;

void create()
{
	set_name("����", ({ "duanyan" , "����"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���Ϻõ���̨,���滹�����һֻ����\n");
	}
}


