// ginseng.c

inherit ITEM;
setup()
{
}
void create()
{
	set_name("�˲�", ({ "ginseng","renshen" }) );
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����ͨ���˲Σ��в������񣬻ָ������Ĺ�Ч��\n");
		set("unit", "��");
		set("value", 250);
	}
}
void init()
{
	add_action("do_use", "eat");
}

int do_use(string arg)
{
	
	if( !this_object()->id(arg) ) return notify_fail("��Ҫ��ʲô��\n");
        this_player()->add("qi", 90);
        this_player()->add("jing", 10);


	 message_vision("$N����һ��" + name() + "�������ָ���һЩ��\n", this_player());
	 destruct(this_object());
	 return 1;

}

