//shufang.c
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short","������");
	set("long",@LONG
�����ǻ������Ĵ����ң��������߰���ķ������֩������
�����ǣ����̲�ס���æ����һ�¡�
LONG);
	set("exits",([
		"south" : __DIR__"houting",
	]));
	if (random(5) > 3)
	set("objects",([
                __DIR__"obj/ftyj-book" : 1,
	]));
	set("no_fight", "1");
	set("no_clean_up", 0);
	set("book_count", 1);
	setup();
}
void init()
{
	add_action("do_zhengli", "zhengli");
}

int do_zhengli()
{

	object ob, me=this_player();
	me->add("qi", -5);
	if ((query("book_count") > 0) && (random(10) == 1))
	{
		message_vision(
HIY"$N�������ͷ�������������������з�����һ���顣\n"NOR,me);
                ob=new("/d/feitian/obj/ftyj-book.c");
		ob->move(me);
message("channel:rumor", HIW"��������ĳ�ˣ�"+this_player()->query("name")+"�ҵ��˷����������������������²ᡣ\n"NOR, users());
		add("book_count", -1);
	}
	else if ((query("book_count") > 0) && (random(10) == 2))
	{
		message_vision(
HIY"$N�������ͷ�������������������з�����һ���顣\n"NOR,me);
                ob=new("/d/feitian/obj/ftyj-book2.c");
		ob->move(me);
message("channel:rumor", HIC"��������ĳ�ˣ�"+this_player()->query("name")+"�ҵ��˷����������������������ϲᡣ\n"NOR, users());
		add("book_count", -1);
	}

	else if ((query("book_count") > 0) && (random(5) == 3))
	{
		message_vision(
HIY"$N�������ͷ�������������������з�����һ���顣\n"NOR,me);
                ob=new("/d/feitian/obj/ft-book.c");
		ob->move(me);
message("channel:rumor", MAG"��������ĳ�ˣ�"+this_player()->query("name")+"�����˷��������������ഫ�����������䡣\n"NOR, users());
		add("book_count", -1);
	}
	else message_vision(
HIY"$N������������˺ð��죬Ū�Ļ�ͷ�����ģ�������һ�����ҡ�\n"NOR,me);
	return 1;
}
