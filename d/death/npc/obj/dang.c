// waterskin.c
#include <login.h>
inherit ITEM;
inherit F_LIQUID;
string *revive_loc= ({
        "/d/city/wumiao",
        "/d/city/wumiao",
});
void init()
{
	add_action("do_eat", "chi");
}
void create()
{
	set_name("����", ({ "aiwan", "wan" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����ɴ���,�����chi�������\n");
		set("unit", "��");
		set("value", 20);
		set("max_liquid", 15);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "alcohol",
		"name": "������",
		"remaining": 5,
		"drunk_apply": 6,
	]) );
}

int do_eat(string arg)
{
   int foo;
        object me = this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
   if(this_player()->is_ghost())
   {
	this_player()->reincarnate();
	this_player()->unconcious();
	this_player()->move(revive_loc[random(sizeof(revive_loc))]);
	this_player()->set("startroom", base_name(environment(this_player())));
	message("vision",
                "���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������\n"
                "�ܾ��ˣ�ֻ����һֱû������\n", environment(this_player()), this_player());
   }	
  return 1;
}

