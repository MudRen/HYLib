//Cracked by Kafei
// Room: /d/xixia/yushufang.c

inherit ROOM;

void create()
{
	set("short", "���鷿");
	set("long", @LONG
�����ǻ��ϵ����鷿����ɫ���㣬����һ���ر�����������ǽ��
�����ӣ��ϴ�ǰ��һ�Ų���ܣ����˲�����ϡ���棬��ǽ�ҷ��š��ͻ�
��ɽ��ͼ������ƽʱ������������Ⱥ�������ºͽӼ����ɵĳ��ӡ�����
��Ȼ��ƫ�򷬹���������ȴ���۲��������д�־��ʱ�ú��˸���Ϊ�١�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"piandian2",
  "east" : __DIR__"xidian",
]));

	set("objects",([
		CLASS_D("lingjiu") + "/li" : 1,			
	]));  
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
