// Room: /d/yanjing/fandian.c

inherit ROOM;

void create()
{
	set("short", "̫�׾�¥");
	set("long", @LONG
̫�׾�¥�Ĳ˺�,�Ƹ���,��˵��¥�ϰ���ڵؽ��е�[��̫��]������
�ٶ�����,���صĸ��̵���ʢ��,��û�в���̫�׾�¥��.����㿴�˿�,û
ʲôֵ��ע���.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/suntaibai.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"street3",
]));

	setup();
	replace_program(ROOM);
}
