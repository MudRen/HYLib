// Room: /d/menggu/yinzhang.c

inherit ROOM;

void create()
{
	set("short", "��ľ��Ӫ��");
	set("long", @LONG
�ɹ���������Ϊ��,�������ڶ�Ǩ����,׷��ˮ��,���޶���,��ëձ��
��������Աη�ѩ,�ͽ����ɹŰ�������Ȼ����ľ���ס��,ȴ��Ȼ������
��,ֻ�Ǳ�Ѱ�����ô���������ֹ.
LONG
	);
set("valid_startroom",1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tiemuzhen.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road",
]));

	setup();
	replace_program(ROOM);
}
