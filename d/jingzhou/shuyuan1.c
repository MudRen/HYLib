// Room: /d/jingzhou/shuyuan1.c
// congw
inherit ROOM;

void create()
{
	set("short", "��Ժ��Ժ");
	set("long", @LONG
��������Ժ�ĺ�Ժ����ɨ�÷ǳ��ɾ��������ǹ��˵�Χǽ��ż���м����������
���ð�����г���ϱ���һ��С�ţ�ͨ��һƬ���֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  
  "north" : __DIR__"shuyuan",
  "south" : __DIR__"shijie",
]));
	
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
