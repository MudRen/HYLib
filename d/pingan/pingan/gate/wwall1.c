inherit ROOM;
void create()
{
        set("short", "����ǽ1");
        set("long", @LONG
�����ĳ�ǽ�ָ��ֺ񣬸���һ�ְ�ȫ�ĸо���ң�����⣬��ɫ����Ұһ������
һ����СС��ũ�����ǵ��ĵ�׺�ſ�����Ұ������ʱ������������Ϧ��б�գ���
��ʤ�ա�Զ�������Ⱥɽ�������˸е�����׳�ۡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"wwall2",
  "south"  : __DIR__"wupgate", 
]));
        set("outdoors", "pingan");
	setup();
}
 
 int valid_leave(object me, string dir) 
{
        object badguy;
 	if ( random(10)>6 && dir == "south" )
{		badguy=new("d/pingan/feizi/feizei");
		badguy->move("d/pingan/gate/wwall1");
 	return notify_fail("��Ȼ�ӳ�������һ����Ӱ��\n");
}
	else 
	{ 
 	return ::valid_leave(me, dir);
	}
}
