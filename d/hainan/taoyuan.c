// Room: /d/hainan/taoyuan.c

inherit ROOM;

void create()
{
	set("short", "�շ���");
	set("long", @LONG
����ľ�ɫʵ����̫���ˣ���������Ұ��Ұ�ݣ�������
Ʈ�����㲻���뵹�ڵ���˯һС����������Ǳ���ֻ�ɺ��ڽ�
�ţ��������к��㡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "enter" : __DIR__"mishi",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xianhe" : 1,
]));
set("no_fight",1);
set("no_magic",1);

	setup();
	replace_program(ROOM);
}
