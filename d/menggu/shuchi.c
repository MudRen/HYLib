// Room: /d/menggu/shuchi.c

inherit ROOM;

void create()
{
	set("short", "����Ӫ��");
	set("long", @LONG
��������ľ��Ĵ����,����Ӫ�ʲ��õñȽϺ���,�����ڱ��ϵĹ���
���ý�����ϸ���.һ�Ŵ���ձ��������Ļ�м�,�����ϵĽ�װ����Ѫ
ɫ�����Ѿ�.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shuchi.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"road2",
]));

	setup();
	replace_program(ROOM);
}
