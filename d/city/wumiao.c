// Room: /city/wumiao.c
// YZC 1995/12/04 

#include <room.h>

inherit ROOM;
void create ()
{
  set ("short", "����");
  set ("long", @LONG
�����������������������������Ϸ������������顰���Һ�ɽ����
���ҡ����������Ƕ�š����ұ������ĸ����֡����˵��ˣ��������������Ϲ�
�Ͼ���������ݡ��Ա��ƺ���һ�����š�
LONG);

  set("no_steal", "1");
  set("item_desc", ([ /* sizeof() == 1 */
  "northwest" : (: look_door,     "northwest" :),
]));
  set("valid_startroom", "1");
//  set("no_get", "1");
  set("no_fight", "1");
  set("no_dazuo", "1");
  set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"wumiao2",
  "east" : __DIR__"beidajie2",
  "west" : __DIR__"zhufang",
  "northwest" : "/d/wizard/guest_room",
  "enter" : "/d/pk/pk/entry",
]));
  set("no_sleep_room", "1");
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/box" : 1,
   "data/npc/bingqipu" : 1,
]));

  setup();
  replace_program(ROOM);
}

void init()
{
	object me;
        add_action("do_quit","get");
	me=this_player();
	me->set("startroom",base_name(environment(me)));
	me->save();
	return;
}

int do_quit(string arg)
{
	if(arg=="all") {
        write(this_player()->query("name")+"�����ﲻ��������\n");
        return 1;
	}
	if(arg=="corpse") {
        write(this_player()->query("name")+"�����ﲻ��������\n");
        return 1;
}  
}