// lit-healpill.c

inherit ITEM;

void create()
{
	set_name("С����", ({ "lit-heal pill","pill" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���ںڵ�Сҩ�裬���������ˡ�\n");
		set("unit", "��");
		set("value", 350);
	}
}
void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	
	if( !this_object()->id(arg) ) return notify_fail("��Ҫ��ʲ�᣿\n");
	if( this_player()->query_temp("block_msg/all"));
		return notify_fail("ʲô��\n");

        this_player()->add("qi", 50 );
        this_player()->add("jing", 50 );

	 
	 message_vision("$N����һ��" + name() + "��������˺ܶࡣ\n", this_player());
	 destruct(this_object());
	return 1;

}

