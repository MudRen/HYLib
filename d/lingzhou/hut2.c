//Cracked by Kafei
// Room: /d/xixia/hut2.c

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����һ�䲻������ݣ����ϻ��кü������СС���ƶ�������͸
�µ�Щ��������㷢������տյ�����ͽ���ıڣ��ݶ��ͽ��������
Щ����������֩�������ذ�Ҳ�������Ƴɣ�ͬ�������˻ҳ���������
�Ե��ر𰵡�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"hut",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
