// Room: /d/yandang/cahuopu.c

inherit ROOM;

void create()
{
	set("short", "�¼�����");
	set("long", @LONG
������ܽ������Ψһ��һ���ӻ���,���ڼ�Ǯ����,�ϰ�����ֺ���
����������������,���а���һ�Ź�̨,����Ļ����ϰ������ϱ��ӻ�,��
�ڱ�ĵط��򲻵��Ķ���,�������������.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"jiedao",
  "enter" : __DIR__"houyuan",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/chenlaoban.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
