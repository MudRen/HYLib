//Edited by fandog, 02/15/2000

#include <ansi.h>
inherit ROOM;

void create()
{

	set("short", "������ͷ");
	set("long", @LONG
��ǰ��һ�����η����Ĵ� (river)������������ǧ������������
�ɴ��������������ٹ����Ͷ�������ȴ��ɴ��ڶɡ�
LONG );
	set("exits", ([
		"west" : __DIR__"hzjie2",
		"south" : __DIR__"matou2",
	]));
	set("item_desc", ([
		"river" : "�������м�ֻ�ɴ���Ҳ��(yell)һ�����Ҿ���������\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "jiangling");
	set("coor/x", -1490);
	set("coor/y", -2110);
	set("coor/z", 0);
  set("yell_about", "����");             // yell ����
  set("river_type", "��");               // �����ϴ�������
  set("need_dodge",300);                 // ��Ҫ�����Ṧ


	setup();
}
