// Room: /d/menggu/chahe.c

inherit ROOM;

void create()
{
	set("short", "���̨Ӫ��");
	set("long", @LONG
���̨����ľ��Ķ���,���Բ��̺�ɱ,�ɹ�����ϲ����,����������
��������Ȯ��ӥ.���̨���䰮��,������Ӫ������˩����Ȯ,Ӫ���л���
��Ȯ������.
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/menggudog.c" : 1,
  __DIR__"npc/chahetai.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road2",
]));

	setup();
	replace_program(ROOM);
}
