
inherit ROOM;

void create()
{
	set("short", "ƽ�����Ͻ�");
	set("long", @LONG
����ƽ�����Ͻ֣����Ľֵ������˲�������һ����������һ��
��С�ķ��ӣ������书��ͷ���ڱ������书���ſ�������д��ѵ������
�ĸ����֡��϶���һ������ĺõط��������������ھ֡��㲻֪������
�ߵ���·�ľ�ͷ��ǰ������ź���û�п���.
LONG
	);
        set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
        set("outdoors", "pingan");
//  __DIR__"npc/man3" : 1,
//]));
	set("exits", ([ /* sizeof() == 5 */
  "east" : __DIR__"congwu",
  "west" : __DIR__"xunlian",
  "north" : __DIR__"nan2",
"in" : "/clone/quarry/dong100"
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
