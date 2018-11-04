#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����������Ҳ�");
	set("long", @LONG
�����Ǽ���ܳ���ҵĵط�����������������������ͻ���ħͷ��
������߳��һʱ��̧ͷһ�ź��ң������߸���������Ľ��֣�
����˭�˲�ʶ��
ע�����������Ⱥ󡣰���ĸ˳��
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"up" : __DIR__"xxci2",
		"down" : __DIR__"shuyuan",
		"south" : __DIR__"xxci3",
	]));
	set("no_fight",1);
	set("no_clean_up", 0);

	set("objects", ([ /* sizeof() == 1 */
		"/d/npc/arnzh" : 1,
		"/d/npc/swh" : 1,
		"/d/npc/oscar" : 1,
		"/d/npc/peter" : 1,
		"/d/npc/rew":1,
		"/d/npc/basic" : 1,
		"/d/npc/goose" : 1,
		"/d/npc/sasa" : 1,
		"/d/npc/rose" : 1,
		"/d/npc/icom" : 1,
	]));

	create_door("south","ľ��","north",DOOR_CLOSED); 	
	setup();
	replace_program(ROOM);
}
