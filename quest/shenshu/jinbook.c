#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIG"��ӹȫ��"NOR, ({ "jin book" }) );
            set("no_put", 1);
            set("value", 0);
            set("shenshu", 1);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	        
            set("unit", "��");
            set("material", "paper");
            set("long", "һ��������ϲ��ɵľ�ᣬ�������(chayue)��������������������С������Ļ���������(try)����\n");
          }

    setup();
}
void init()
{
   add_action("do_cha","chayue");
   add_action("do_try","try");
}
int do_cha(string arg)
{
	object me,ob;
	int exp,pot,score,i;
	me =this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
message("channel:chat", HIC"���������š�"GRN + me->query("name")+"�õ�����"+HIY":" + ob->query("name")+HIG"����\n"NOR,users() );
	destruct(this_object());
return 1;
}
int do_try(string arg)
{
	object me,newbook,ob;
	me = this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	newbook =new(__DIR__"bestbook");

    if (!(ob = present("gulong book", me))
        )
	tell_object(me,"�����û��.\n");
   else{
        if( ob->query("ownmake"))
	return notify_fail("�������мٻ��ɡ�\n");
        if( !ob->query("shenshu"))
	return notify_fail("�������мٻ��ɡ�\n");
        if(userp(ob))
	return notify_fail("�������мٻ��ɡ�\n");
        if( ob->is_character() || ob->is_corpse() )
	return notify_fail("�������мٻ��ɡ�\n");
        message_vision("$N���Ű�������ǿ������������ϳ�һ�������Ͼ�Ȼ�ɹ��ˡ�\n", me);
	newbook->move(me);
	destruct(present("gulong book",me));
	destruct(this_object());}return 1;
}
