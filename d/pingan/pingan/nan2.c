
inherit ROOM;

void create()
{
	set("short", "ƽ�����Ͻ�");
	set("long", @LONG
����ƽ�����Ͻ֣����Ľֵ������˲�������һ�����ֶ������
��һ���������ġ��ɽ��������㿴���ܾ����е㲻�Ծ���������
һ����ݣ���������˽�ȥɱ���ѡ�
LONG
	);
set("outdoors","/d/pingan");
        set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
	set("no_clean_up", 0);
//	set("objects", ([ /* sizeof() == 2 */
//  __DIR__"npc/man2" : 1,
//]));
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"qiyuan/qiyuan1",
  "north" : __DIR__"nan1",
  "west" : __DIR__"duchang/club",
  "south" : __DIR__"nan3",
]));
	set("outdoors", "pingan");

	setup();
	replace_program(ROOM);
}
