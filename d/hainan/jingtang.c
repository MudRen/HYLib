// Room: /d/hainan/jingtang
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG
�����ֵķ��,ֻ�����еĹ����ϰ���һ�����¹���.�����ˮĥʯ 
���ϰ��˸�����.�Ա���һ��СС��ľ��.����һ������,��Ȼ��һ������ 
����.�벻�����ִ��е�ʥ�ؾ�Ȼ�������ӵ�. 
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/master.c" : 1,
]));
set("valid_startroom",1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"baiyunan",
  "west" : __DIR__"shutang",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "���¹���" : "һ���մɵİ��¹���,�߶�����.���ֶ��о�ƿ,����б���� 
�½�,Ĵָ��ָ���۱�ƿӡ. 
",
]));
	create_door("south", "����", "north", DOOR_CLOSED);
  setup();

}

int valid_leave(object me, string dir)
{
	object ob;
	if ((dir=="west") && me->query("family/family_name")!="������")
	{
		ob = present("fan yin", this_object());
	if(objectp(ob)&&!userp(ob)&&living(ob))
		{
			message_vision("\n$N���ְ�$n��ס˵����������,������أ�\n", ob, me);
			return notify_fail("");
		}
	}
	return ::valid_leave(me, dir);
}
