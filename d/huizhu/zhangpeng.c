// Room: /d/huizhu/zhangpeng.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ţƤ�����Լ����ʮ���ˡ��������Ż����ĵ�̺��������������
�Ļ��ƣ������������ա�̺���м���Ź��衣�����Ǽ���������ӣ�һ
�߻����Ű�������.
LONG
	);
set("valid_startroom",1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/muzhuolun.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"buluo1",
]));

	setup();
	replace_program(ROOM);
}
