// oil.c

inherit ITEM;
setup()
{
}
void create()
{
	set_name("�����", ({ "wanjin oil","oil","wanjin" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һСƿ��ɫ��ҩ�ͣ�����һ�ֱ��ɵ�������ʹ��(use)������������á�\n");
		set("unit", "ƿ");
		set("value", 150);
		set("oil_left",5);
	}
}
void init()
{
	add_action("do_use", "use");
}

int do_use(string arg)
{
	
	if( !this_object()->id(arg) ) return notify_fail("��ʹ��ʲô��\n");
        this_player()->add("qi",10);
                this_player()->add("jing",10);
        add("oil_left",-1);

	 message_vision("$N�ó�һ��С��ƿ������һЩ" + name() + "���������һЩ��\n", this_player());
	 if(!query("oil_left")) {
		message_vision("$N��С��ƿ��" + name() + "�����ˡ�\n",this_player());
		destruct(this_object()); }
	 return 1;

}

