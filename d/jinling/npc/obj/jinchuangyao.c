// jinchuangyao.c

inherit ITEM;
setup()
{
}
void create()
{
	set_name("��ҩ", ({ "jinchuang yao","yao","jinchuang" }) );
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����ɫ�ĸ�ҩ������һ�ִ̱ǵ�ҩ�㣬����(tie)���˿��ϣ����������á�\n");
		set("unit", "��");
		set("value", 200);
	}
}
void init()
{
	add_action("do_use", "tie");
}

int do_use(string arg)
{
	
	if( !this_object()->id(arg) ) return notify_fail("����ʲô��\n");
        this_player()->add("qi", 30 );
        this_player()->add("jing", 10 );


	 message_vision("$N�ó�һ��" + name() + "�����˿��ϣ��о��ö��ˡ�\n", this_player());
	 destruct(this_object());
	 return 1;

}

