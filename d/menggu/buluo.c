// Room: /d/menggu/buluo.c

inherit ROOM;

void create()
{
	set("short", "��ľ�沿��");
	set("long", @LONG
��ľ�沿���ǵ����ɹŲ�ԭ����ǿʢ��һ��,������������ı,������
��,��ԭ�ϵ�Ӣ�۶�Ը��Ϊ��Ч��,��Ŀ������֮��,ţ����׳,������ɹ�
���ڸ��˾�Ŀ���������Ĳ�ԭ.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "menggu");
	set("exits", ([ /* sizeof() == 3 */
  "northwest" : __DIR__"buluo2",
  "north" : __DIR__"buluo1",
  "southwest" : __DIR__"caoyuan6",
]));

	setup();
	replace_program(ROOM);
}
